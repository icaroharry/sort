#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_opt.c"
#include "array.c"
#include "sort.c"

int main(int argc, char **argv) {
    int i, method, size, array_type, print_vector = 0;
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
    
    printf("-- Analise da ordenacao --\n\n");
    printf("Algoritmo utilizado: %s\n", get_method_name(method));
    printf("Tipo do vetor: %s\n", get_array_type_name(array_type));
    printf("Tamanho do vetor: %d\n", size);
    printf("Numero de comparacoes: %d\n", get_comparisons());
    printf("Numero de trocas: %d\n", get_swaps());
    printf("Tempo gasto: %f s\n", get_elapsed_time());
    if(print_vector){
        printf("Vetor original: ");
        for(i=0; i<size; i++){
            printf("%d ", vet_aux[i]);
        }
        printf("\n\nVetor ordenado: ");            
        for(i=0; i<size; i++){
            printf("%d ", vet[i]);
        }
    }
    printf("\n\n");
	return 0;
}