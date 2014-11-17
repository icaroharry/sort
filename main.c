#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.c"
#include "get_opt.c"

int main(int argc, char *argv[]) {
	
    int *method, *size, *array_type;
    get_opt(argv, method, size, array_type);

    printf("%d %d %d\n", *method, *size, *array_type);

	int *vet = generate_array(*size, DESCENDING_ORDER);

	for(int i = 0; i < *size; i++) {
		printf("%d ", vet[i]);
	}
	return 0;
}