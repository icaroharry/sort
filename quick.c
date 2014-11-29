void quick_sort(int vet[], int left, int right) {
    int i, j, x, y, middle;
    i = left;
    j = right;

    middle = vet[(i+j) / 2];
    if((middle>i && middle<j)||(middle>j && middle<i)){
        x = middle;
    }else if(((i)>middle && (i)<(j)) || ((i)>(j) && (i)<middle)){
        x = i;
    }
    
    else if(((j)>middle && (j)<(i)) || ((j)>(i) && (j)<middle)){
        x = j;
    }
    else{
        x = middle;
    }

    while(i <= j){
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
    if(j > left){
        quick_sort(vet, left, j);
    }
    if(i < right){
        quick_sort(vet, i, right);
    }
}