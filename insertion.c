/**
 * Insertion sort implementation
 * @complexity O(n²) 
 * @param int* array Array that will be sorted
 * @param int  size Size of the array
 */
void insertion_sort(int *array, int size) {
   int i, j, selected;
   for (i = 1; i < size; i++){
      selected = array[i];
      j = i - 1;
      while ((j >= 0) && (selected < array[j])) {
         array[j+1] = array[j];
         j--;
         number_of_comparisons++;
      }
      number_of_swaps++;
      array[j+1] = selected;
   }
}