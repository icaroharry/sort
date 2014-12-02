/*
 * =====================================================================================
 *
 *       Filename:  cuda_sort.h
 *
 *    Description:  Implements the interface which allows C compiled code to access our
 *                  CUDA sorting kernels.
 *
 *        Version:  1.0
 *        Created:  12/01/2014 03:05:42 AM
 *       Revision:  none
 *       Compiler:  nvcc v6.0.1
 *
 *         Author:  Eugenio Pacceli Reis da Fonseca e Icaro Harry
 *   Organization:  DCC/UFMG
 *
 * =====================================================================================
 */

// Used in qsort, to stop it when recursion is too deep or there is not enough elements
// unsorted to justify another stream, according to NVIDIA's simple quick sort sample.
#define MAX_DEPTH       16
#define INSERTION_SORT  32

// Interface to call CUDA Quick Sort
void gpu_qsort(int *data, int nitems);
// Interface to call CUDA Merge Sort
void gpumerge_sort(int* a,int n);
