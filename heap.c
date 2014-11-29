void heap_sort(int vet[], int n){
  int i = n/2, pai, filho, t;
 
   for (;;){
      if (i > 0){
          i--;
          t = vet[i];
      }
      else{
          n--;
          if (n == 0)
             return;
          t = vet[n];
          vet[n] = vet[0];
      }
 
      pai = i;
 
      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i*2;
 
      while (filho < n){
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (vet[filho + 1] > vet[filho])){
            filho++;   
            number_of_comparisons++;
          }              
          if (vet[filho] > t){
             number_of_comparisons++;
             vet[pai] = vet[filho];
             pai = filho;
             filho = pai*2 + 1;
             number_of_swaps++;
          }
          else
             break;
      }
      vet[pai] = t;
   }
}