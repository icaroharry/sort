/*
 * =====================================================================================
 *
 *       Filename:  cuda_sort.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/01/2014 03:05:42 AM
 *       Revision:  none
 *       Compiler:  nvcc
 *
 *         Author:  Eugenio Pacceli Reis da Fonseca e Icaro Harry,
 *   Organization:
 *
 * =====================================================================================
 */

#define MAX_DEPTH       16
#define INSERTION_SORT  32

void gpu_qsort(int *data, int nitems);
void gpumerge_sort(int* a,int n);
