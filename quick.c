/**
 * Quick sort implementation
 * @complexity O(n log n)
 * @param int[] vet   
 * @param int   left  Beggining of the array
 * @param int   right End of the array
 */
void quick_sort(int vet[], int left, int right) {
    int i, j, x, y, middle;
    i = left;
    j = right;

    middle = vet[(i+j) / 2];
    
    /** 
     * To avoid the worst case, we've to select the middle element 
     * between 3 random elements
     */
    if((middle > i && middle < j)||(middle > j && middle < i)){
        x = middle;
    } else if((i > middle && i < j) || (i > j && i < middle)){
        x = i;
    } else if((j > middle && j < i) || (j > i && j < middle)){
        x = j;
    } else {
        x = middle;
    }

    while(i <= j) {
        while(vet[i] < x && i < right){
            i++;
            number_of_comparisons++;
        }
        while(vet[j] > x && j > left){
            j--;
            number_of_comparisons++;
        }
        if(i <= j){
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
            number_of_swaps++;
        }
    }
    /** Recursive call for the function to the left part of the array */
    if(j > left){
        quick_sort(vet, left, j);
    }
    
    /** Recursive call for the function to the right part of the array */
    if(i < right){
        quick_sort(vet, i, right);
    }
}