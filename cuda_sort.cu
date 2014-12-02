/*
* 
* Nvidia's Simple Quick Sort Sample was used as a basis and modified to meet our
* CPU algorithm. Check CUDA TOOLKIT 6.0 SAMPLES.
*
* As requested by NVIDIA:
* Copyright 1993-2014 NVIDIA Corporation.  All rights reserved.
* =============================================================================
* Please refer to the NVIDIA end user license agreement (EULA) associated
* with this source code for terms and conditions that govern your use of
* this software. Any use, reproduction, disclosure, or distribution of
* this software and related documentation outside the terms of the EULA
* is strictly prohibited.
* =============================================================================
* Merge sort written by us, based on a top down implementation of merge sort
*
* Eugenio Pacceli Reis da Fonseca
* Ícaro Pinto Coelho Harry
* DCC/UFMG 2014
* Compiler:: NVCC v6.0.1
* Debian testing/sid 64 bits
*/

#include <helper_cuda.h>
#include <helper_string.h>

extern "C" {
    #include "cuda_sort.h"
}

// NVIDIA's
// Selection sort used when depth gets too big or the number of elements drops
// below a threshold.
__device__ void selection_sort( int *data, int left, int right )
{
  for( int i = left ; i <= right ; ++i ){
    int min_val = data[i];
    int min_idx = i;

    // Find the smallest value in the range [left, right].
    for( int j = i+1 ; j <= right ; ++j ){
      int val_j = data[j];
      if( val_j < min_val ){
        min_idx = j;
        min_val = val_j;
      }
    }

    // Swap the values.
    if( i != min_idx ){
      data[min_idx] = data[i];
      data[i] = min_val;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
// Very basic quicksort algorithm, recursively launching the next level.
////////////////////////////////////////////////////////////////////////////////
__global__ void cdp_simple_quicksort(int *data, int left, int right, int depth ){
    //If we're too deep or there are few elements left, we use an insertion sort...
    if( depth >= MAX_DEPTH || right-left <= INSERTION_SORT ){
        selection_sort( data, left, right );
        return;
    }

    cudaStream_t s,s1;
    int *lptr = data+left;
    int *rptr = data+right;
    int  pivot = data[(left+right)/2];

    int lval;
    int rval;

    int nright, nleft;

    // Do the partitioning.
    while (lptr <= rptr){
        // Find the next left- and right-hand values to swap
        lval = *lptr;
        rval = *rptr;

        // Move the left pointer as long as the pointed element is smaller than the pivot.
        while (lval < pivot && lptr < data+right){
            lptr++;
            lval = *lptr;
        }

        // Move the right pointer as long as the pointed element is larger than the pivot.
        while (rval > pivot && rptr > data+left){
            rptr--;
            rval = *rptr;
        }

        // If the swap points are valid, do the swap!
        if (lptr <= rptr){
            *lptr = rval;
            *rptr = lval;
            lptr++;
            rptr--;
        }
    }

    // Now the recursive part
    nright = rptr - data;
    nleft  = lptr - data;

    // Launch a new block to sort the left part.
    if (left < (rptr-data)){
        cudaStreamCreateWithFlags(&s, cudaStreamNonBlocking);
        cdp_simple_quicksort<<< 1, 1, 0, s >>>(data, left, nright, depth+1);
        cudaStreamDestroy(s);
    }

    // Launch a new block to sort the right part.
    if ((lptr-data) < right){
        cudaStreamCreateWithFlags(&s1, cudaStreamNonBlocking);
        cdp_simple_quicksort<<< 1, 1, 0, s1 >>>(data, nleft, right, depth+1);
        cudaStreamDestroy(s1);
    }
}


// gcc compiled code will call this function to access CUDA Quick Sort.
// This calls the kernel, which is recursive. Waits for it, then copies it's
// output back to CPU readable memory.
extern "C"
void gpu_qsort(int *data, int n){
    int* gpuData;
    int left = 0;
    int right = n-1;

    // Prepare CDP for the max depth 'MAX_DEPTH'.
    cudaDeviceSetLimit(cudaLimitDevRuntimeSyncDepth, MAX_DEPTH);

    // Allocate GPU memory.
    cudaMalloc((void**)&gpuData,n*sizeof(int));
    cudaMemcpy(gpuData,data, n*sizeof(int), cudaMemcpyHostToDevice);

    // Launch on device
    cdp_simple_quicksort<<< 1, 1 >>>(gpuData, left, right, 0);
    cudaDeviceSynchronize();

    // Copy back
    cudaMemcpy(data,gpuData, n*sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(gpuData);
    // cudaDeviceReset causes the driver to clean up all state. While
    // not mandatory in normal operation, it is good practice.  It is also
    // needed to ensure correct operation when the application is being
    // profiled. Calling cudaDeviceReset causes all profile data to be
    // flushed before the application exits
    cudaDeviceReset();
}

// Our MergeSort implementation. Really simple, based on the normal top down
// implementation. Not inplace.
__global__ void simple_mergesort(int* data,int *dataAux,int begin,int end, int depth){
    int middle = (end+begin)/2;
    int i0 = begin;
    int i1 = middle;
    int index;
    int n = end-begin;

    // Used to implement recursions using CUDA parallelism.
    cudaStream_t s,s1;

    if(n < 2){
        return;
    }

    // Launches a new block to sort the left part.
    cudaStreamCreateWithFlags(&s,cudaStreamNonBlocking);
    simple_mergesort<<< 1, 1, 0, s >>>(data,dataAux, begin, middle, depth+1);
    cudaStreamDestroy(s);

    // Launches a new block to sort the right part.
    cudaStreamCreateWithFlags(&s1,cudaStreamNonBlocking);
    simple_mergesort<<< 1, 1, 0, s1 >>>(data,dataAux, middle, end, depth+1);
    cudaStreamDestroy(s1);

    // Waits for children's work.
    cudaDeviceSynchronize();

    // Merges children's generated partition.
    // Does the merging using the auxiliary memory.
    for (index = begin; index < end; index++) {
        if (i0 < middle && (i1 >= end || data[i0] <= data[i1])){
            dataAux[index] = data[i0];
            i0++;
        }else{
            dataAux[index] = data[i1];
            i1++;
        }
    }

    // Copies from the auxiliary memory to the main memory.
    // Note that each thread operates a different partition,
    // and the auxiliary memory has exact the same size of the main
    // memory, so the threads never write or read on the same
    // memory position concurrently, since one must wait it's children
    // to merge their partitions.
    for(index = begin; index < end; index++){
        data[index] = dataAux[index];
    }
}

// gcc compiled code will call this function to access CUDA Merge Sort.
// This calls the kernel, which is recursive. Waits for it, then copies it's
// output back to CPU readable memory.
extern "C"
void gpumerge_sort(int* a,int n){
    int* gpuData;
    int* gpuAuxData;
    int left = 0;
    int right = n;

    // Prepare CDP for the max depth 'MAX_DEPTH'.
    cudaDeviceSetLimit(cudaLimitDevRuntimeSyncDepth, MAX_DEPTH);

    // Allocate GPU memory.
    cudaMalloc((void**)&gpuData,n*sizeof(int));
    cudaMalloc((void**)&gpuAuxData,n*sizeof(int));
    cudaMemcpy(gpuData,a, n*sizeof(int), cudaMemcpyHostToDevice);

    // Launch on device
    simple_mergesort<<< 1, 1 >>>(gpuData,gpuAuxData, left, right, 0);
    cudaDeviceSynchronize();

    // Copy back
    cudaMemcpy(a,gpuData, n*sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(gpuAuxData);
    cudaFree(gpuData);
    // cudaDeviceReset causes the driver to clean up all state. While
    // not mandatory in normal operation, it is good practice.  It is also
    // needed to ensure correct operation when the application is being
    // profiled. Calling cudaDeviceReset causes all profile data to be
    // flushed before the application exits
    cudaDeviceReset();
}


