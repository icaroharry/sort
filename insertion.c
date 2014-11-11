void insertion_sort(int vet[], int size) {
	int j, aux;
	for(int i = 1; i < size; i++) {
		j = i-1;
		while(j >= 0 && vet[j] > vet[j+1]) {
			aux = vet[j];
			vet[j] = vet[j+1];
			vet[j+1] = aux; 
			j--;
		}
	}
}