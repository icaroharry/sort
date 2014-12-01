/*
 * =====================================================================================
 *
 *       Filename:  swap.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/30/2014 04:48:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include"sort.h"
#include"cuda_sort.h"
#include<string.h>
#include<stdlib.h>

clock_t start, end;
double elapsed_time;
int numberOfComparisons;
int numberOfSwaps;

void selection_sort(int *vet, int tam){
    int i, j, min, aux;
      for (i = 0; i < (tam-1); i++){
        min = i;
        for (j = (i+1); j < tam; j++) {
            numberOfComparisons++;
            if(vet[j] < vet[min]){
                min = j;
              }
        }
        if (i != min){
            aux = vet[i];
              vet[i] = vet[min];
              vet[min] = aux;
              numberOfSwaps++;
        }
    }
}

void insertion_sort(int *array, int size) {
   int i, j, selected;
   for (i = 1; i < size; i++){
      selected = array[i];
      j = i - 1;
      while ((j >= 0) && (selected < array[j])) {
         array[j+1] = array[j];
         j--;
         numberOfComparisons++;
      }
      numberOfSwaps++;
      array[j+1] = selected;
   }
}

void shell_sort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while (gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
                numberOfComparisons++;
                numberOfSwaps++;
            }
            vet [j + gap] = value;
        }
    }
}

void quick_sort(int vet[], int left, int right) {
    int i, j, pivot, y;
    i = left;
    j = right;

    pivot = vet[(i+j) / 2];

    while(i <= j) {
        while(vet[i] < pivot && i < right){
            i++;
            numberOfComparisons++;
        }
        while(vet[j] > pivot && j > left){
            j--;
            numberOfComparisons++;
        }
        if(i <= j){
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
            numberOfSwaps++;
        }
    }
    /** Recursive call for the function to the left part of the array */
    if(j > left){
        quick_sort(vet, left, j);
    }

    /** Recursive call for the function to the right part of the array */
    if(i < right){
        quick_sort(vet, i, right);
    }
}

void heap_sort(int vet[], int n){
  int i = n/2, pai, filho, t;

   for (;;){
      if (i > 0){
          i--;
          t = vet[i];
      }
      else{
          n--;
          if (n == 0)
             return;
          t = vet[n];
          vet[n] = vet[0];
      }

      pai = i;

      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i*2;

      while (filho < n){
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (vet[filho + 1] > vet[filho])){
            filho++;
            numberOfComparisons++;
          }
          if (vet[filho] > t){
             numberOfComparisons++;
             vet[pai] = vet[filho];
             pai = filho;
             filho = pai*2 + 1;
             numberOfSwaps++;
          }
          else
             break;
      }
      vet[pai] = t;
   }
}

void top_down_merge(int* a,int begin,int end,int* b){
    int middle = (end+begin)/2;
    int i0 = begin;
    int i1 = middle;
    int index;
    int n = end-begin;

    if(n < 2){
        return;
    }

    top_down_merge(a, begin, middle, b);
    top_down_merge(a, middle, end, b);

    for (index = begin; index < end; index++) {
        if (i0 < middle && (i1 >= end || a[i0] <= a[i1])){
            b[index] = a[i0];
            i0++;
        }else{
            b[index] = a[i1];
            i1++;
        }
        numberOfComparisons++;
        numberOfSwaps++;
    }

    memcpy((a+begin),(b+begin),sizeof(int)*(n));
    numberOfSwaps+= n;
}

void merge_sort(int* a,int n){
    int* b = (int*)malloc(sizeof(int)*n);
    top_down_merge(a, 0, n, b);
    free(b);
}

int* sort_array(int *vet, int size, int method){

    switch(method){
        case SELECTION:
            start = clock();
            selection_sort(vet, size);
            end = clock();
        break;

        case INSERTION:
            start = clock();
            insertion_sort(vet, size);
            end = clock();
        break;

        case SHELL:
            start = clock();
            shell_sort(vet, size);
            end = clock();
        break;

        case QUICK:
            start = clock();
            quick_sort(vet, 0, size);
            end = clock();
        break;

        case HEAP:
            start = clock();
            heap_sort(vet, size);
            end = clock();
        break;

        case MERGE:
            start = clock();
            merge_sort(vet, size);
            end = clock();
        break;

        case GPUQUICK:
            start = clock();
            gpu_qsort(vet,size);
            end = clock();
        break;

        case GPUMERGE:
            start = clock();
            gpumerge_sort(vet,size);
            end = clock();
    }
    elapsed_time = (((double)(end-start))/CLOCKS_PER_SEC);
    return vet;
}

double get_elapsed_time(){
    return elapsed_time;
}

int get_swaps(){
    return numberOfSwaps;
}

int get_comparisons(){
    return numberOfComparisons;
}
