/*
 * =====================================================================================
 *
 *       Filename:  array.h
 *
 *    Description:
 *
 *       Compiler:  nvcc V6.0.1
 *
 *         Author:  Eugenio Pacceli Reis da Fonseca
 *                  Icaro Harry
 *
 *   Organization: DCC/UFMG
 *
 * =====================================================================================
 */

#ifndef ARRAY_OPERATIONS
#define ARRAY_OPERATIONS 1

#define RANDOM_ORDER     0
#define ASCENDING_ORDER  1
#define DESCENDING_ORDER 2
#define ALMOST_ORDERED   3

/**
 * Function that fills an array with random integers
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void random_array(int *array, int size);

/**
 * Function that fills an array with integers in ascending order
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void ascending_array(int *array, int size);

/**
 * Function that fills an array with integers in ascending order
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void descending_array(int *array, int size);

/**
 * Function that fills 90% of an array with integers in ascending order
 * an the other 10% with random integers
 * @param int* array Reference to the array that will be filled
 * @param int  size  Number of elements
 */
void almost_ordered_array(int *array, int size);

/**
 * Function that receives the size and the organization of the
 * required array and returns it filled.
 * @param  int   size          Size of the array
 * @param  int   organization  How the array will be filled
 * @return int[]               Filled array
 */
int* generate_array(int size, int organization);

#endif
