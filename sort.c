#include <time.h>
#include "selection.c"
#include "insertion.c"
#include "shell.c"
#include "quick.c"
#include "heap.c"

#define selection  0
#define insertion  1
#define shell      2
#define quick      3
#define heap       4

clock_t start, end;
double elapsed_time;



int* sort_array(int *vet, int size, int method){
	
	switch(method){
		case selection:
			start = clock();
				selection_sort(vet, size);
			end = clock();
		break;

		case insertion:
			start = clock();
				insertion_sort(vet, size);
			end = clock();
		break;

		case shell:
			start = clock();
				shell_sort(vet, size);
			end = clock();
		break;

		case quick:
			start = clock();
				quick_sort(vet, 0, size);
			end = clock();
		break;

		case heap:
			start = clock();
				heap_sort(vet, size);
			end = clock();
		break;
	}
	elapsed_time = (((double)(end-start))/CLOCKS_PER_SEC);
}

double get_elapsed_time(){
	return elapsed_time;
}