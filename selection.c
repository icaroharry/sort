#include "util.c"

void selection_sort(int *vet, int tam){ 
	int i, j, min, aux;
  	for (i = 0; i < (tam-1); i++){
		min = i;
		for (j = (i+1); j < tam; j++) {
			number_of_comparisons++;
			if(vet[j] < vet[min]){
		    	min = j;
		  	}
		}
		if (i != min){
			aux = vet[i];
		  	vet[i] = vet[min];
		  	vet[min] = aux;
		  	number_of_swaps++;
		}
  	}
}