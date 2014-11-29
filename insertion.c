void insertion_sort(int *vet, int tam) {
   int i, j, eleito;
   for (i = 1; i < tam; i++){
      eleito = vet[i];
      j = i - 1;
      while ((j>=0) && (eleito < vet[j])) {
         vet[j+1] = vet[j];
         j--;
         number_of_comparisons++;
         number_of_swaps++;
      }
      vet[j+1] = eleito;
   }
}