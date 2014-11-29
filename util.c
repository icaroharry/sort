#include <stdlib.h>

/** Integer that's incremented every time that the compare function is called */
int number_of_comparisons = 0;
/** Integer that's incremented every time that the swap function is called */
int number_of_swaps = 0;

int get_swaps(){
    return number_of_swaps;
}

int get_comparisons(){
    return number_of_comparisons;
}