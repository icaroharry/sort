void bubble_sort(int vet[], int size) {
	int aux;
	
	for(int i = size; i >= 1; i--) {
		for(int j = 1; j < size; j++) {
			if(vet[j-1] > vet[j]) {
				aux = vet[j-1];
				vet[j-1] = vet[j];
				vet[j] = aux; 
			}
		}
	}
}