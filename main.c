#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_opt.h"
#include "array.h"
#include "sort.h"

int main(int argc, char **argv) {
    int i, method, size, array_type, print_vector = 0;

    if(!check_opt(argc)){
        fprintf(stderr,"Not enough parameters\n");
        fprintf(stderr,"Expected: -a SORTTYPE -n ARRAYSIZE -s ARRAYSTATE [-P]\n");
        fprintf(stderr,"Please read the doc.\n");
        return 1;
    }

    get_opt(argc, argv, &method, &size, &array_type, &print_vector);

    // Create the vector with the specified size and situation
    int *vet = generate_array(size, array_type);
    int *vet_aux = (int*)malloc(sizeof(int)*size);
    // Create a copy of the vector to print it berfore and after it is sorted in case this option is enabled
    for(i=0; i<size; i++){
        vet_aux[i] = vet[i];
    }
    // Sort the array
    sort_array(vet, size, method);

    printf("-- Analysis --\n\n");
    printf("Sorting algorithm: %s\n", get_method_name(method));
    printf("Array type: %s\n", get_array_type_name(array_type));
    printf("Array size: %d\n", size);
    printf("Number of comparisons: %d\n", get_comparisons());
    printf("Number of swaps: %d\n", get_swaps());
    printf("Time elapsed: %f s\n", get_elapsed_time());
    if(print_vector){
        printf("Original: ");
        for(i=0; i<size; i++){
            printf("%d ", vet_aux[i]);
        }
        printf("\n\nSorted: ");
        for(i=0; i<size; i++){
            printf("%d ", vet[i]);
        }
    }
    free(vet);
    free(vet_aux);
    printf("\n\n");
    return 0;
}
