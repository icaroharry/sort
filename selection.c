#include "util.c"

void selection_sort(int vet[], int size) {
	int minor, aux;
	for(int i = 0; i < size; i++) {
		minor = i;
		for(int j = i + 1; j < size; j++) {
			if(compare(&vet[j], &vet[minor]) == 0) 
				minor = j;
		}
		swap(&vet[i], &vet[minor]);
	}
}