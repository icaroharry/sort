#include <stdio.h>
#include "bubble.c"
#include "selection.c"
#include "insertion.c"

int main() {
	int vet[10] = {10,9,8,7,6,5,4,3,2,1};
	int size = 10;
	insertion_sort(vet, size);

	for(int i = 0; i < size; i++) {
		printf("%d ", vet[i]);
	}
	return 0;
}