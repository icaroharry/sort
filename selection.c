void selection_sort(int vet[], int size) {
	int minor, aux;
	for(int i = 0; i < size; i++) {
		minor = i;
		for(int j = i + 1; j < size; j++) {
			if(vet[j] < vet[minor])
				minor = j;
		}
		aux = vet[i];
		vet[i] = vet[minor];
		vet[minor] = aux; 
	}
}