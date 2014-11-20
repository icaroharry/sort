#include <stdlib.h>

/** Integer that's incremented every time that the compare function is called */
int number_of_comparisons = 0;
/** Integer that's incremented every time that the swap function is called */
int number_of_swaps = 0;

/**
 * Swap the values of a and b
 * @param int* a 
 * @param int* b 
 */
void swap(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    number_of_swaps++;
}

/**
 * Compare two integers a and b. Returning 0 if they have the same
 * value, or -1 if not.
 * @param  int* a 
 * @param  int* b 
 * @return int  
 */
int compare(int* a, int* b) {
    number_of_comparisons++;
    if(*a == *b)
        return 0; 
    else
        return -1;
}