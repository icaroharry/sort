#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define undefined -1

#define selection  0
#define insertion  1
#define shell      2
#define quick      3
#define heap       4

#define random     0
#define ascending  1
#define descending 2
#define almost     3

static const char *optString = "a:n:s:P";

int get_sort_method(char method[]) {
    int selected_method;
    //printf("%d\n", selected_method);
    if(strcmp(method, "selection") == 0)
        selected_method = selection;
    else if(strcmp(method, "insertion") == 0)
        selected_method = insertion;
    else if(strcmp(method, "shell") == 0)
        selected_method = shell;
    else if(strcmp(method, "quick") == 0)
        selected_method = quick;
    else if(strcmp(method, "heap") == 0)
        selected_method = heap;
    else
        selected_method = undefined;
    return selected_method;
}

int get_array_size(char method[]) {
    int size = atoi(method);
    if(size < 0 || size > 1000000)
        size = undefined;
    return size;
}

int get_array_type(char type[]) {
    int selected_type;
    if(strcmp(type, "random") == 0)
        selected_type = random;
    else if(strcmp(type, "ascending") == 0)
        selected_type = ascending;
    else if(strcmp(type, "descending") == 0)
        selected_type = descending;
    else if(strcmp(type, "almost") == 0)
        selected_type = almost;
    else
        selected_type = undefined;
    return selected_type;
}

void get_opt(int argc, char **argv, int *method, int *size, int *array_type, int *print_vector) {
    int opt = 0;
    opt = getopt(argc, argv, optString);
    //a:n:s:p
    while(opt != -1) {
        switch(opt) {
            case 'a': // algorithm
                *method = get_sort_method(optarg);
                break;
                
            case 'n': // number of elements
                *size   = get_array_size(optarg);
                break;

            case 's': // (vector) situation
                *array_type   = get_array_type(optarg);
                break;
            
            case 'P': // print
                *print_vector = 1;
            break;
                
            default:
                /* You won't actually get here. */
                break;
        }
        
        opt = getopt(argc, argv, optString);  
    }
}

char* get_method_name(int method){
    char *name;
    switch(method){
        case selection:
            name = "Selecao";
            break;
        case insertion:
            name = "Insercao";
            break;
        case shell:
            name = "Shell";
            break;
        case quick:
            name = "Quick";
            break;
        case heap:
            name = "Heap";
            break;
        case undefined:
            name = " - ";
            break;
        default:            
            break;
    }
    return name;
}

char* get_array_type_name(int type){
    char *name;
    switch(type){
        case random:
            name = "Aleatorio";
            break;
        case ascending:
            name = "Ordenado";
            break;
        case descending:
            name = "Inversamente ordenado";
            break;
        case almost:
            name = "Quase ordenado";
            break;
        case undefined:
            name = " - ";
            break;
        default:
            break;
    }
    return name;
}