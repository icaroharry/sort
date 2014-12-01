#include "array.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * Function that fills an array with random integers
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void random_array(int *array, int size) {
    srand(time(NULL));
    int i;
    for(i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
}

/**
 * Function that fills an array with integers in ascending order
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void ascending_array(int *array, int size) {
    int i;
    for(i = 1; i <= size; i++) {
        array[i] = i;
    }
}

/**
 * Function that fills an array with integers in ascending order
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void descending_array(int *array, int size) {
    int i, j;
    for(i = 0, j = size; i < size; i++, j--) {
        array[i] = j;
    }
}

/**
 * Function that fills 90% of an array with integers in ascending order
 * an the other 10% with random integers
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void almost_ordered_array(int *array, int size) {
    srand(time(NULL));
    int ninety_percent_size = (int)size/10 * 9;
    int i = 0;
    for(i = 1; i <= ninety_percent_size; i++) {
        array[i] = i;
    }

    for(i = ninety_percent_size; i < size; i++) {
        array[i] = rand() % (size - ninety_percent_size) + ninety_percent_size;
    }
}

/**
 * Function that receives the size and the organization of the
 * required array and returns it filled.
 * @param  int   size          Size of the array
 * @param  int   organization  How the array will be filled
 * @return int[]               Filled array
 */
int* generate_array(int size, int organization) {
    int* array;
    array = (int*)malloc(size*sizeof(int));

    if(array){
        switch(organization) {
            case RANDOM_ORDER:
            random_array(array, size);
            break;
            case ASCENDING_ORDER:
            ascending_array(array, size);
            break;
            case DESCENDING_ORDER:
            descending_array(array, size);
            break;
            case ALMOST_ORDERED:
            almost_ordered_array(array, size);
            break;
        }
    }
    return array;
}
