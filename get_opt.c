#include "get_opt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char *optString = "a:n:s:P";

int get_sort_method(char method[]) {
    int selected_method;
    //printf("%d\n", selected_method);
    if(strcmp(method, "selection") == 0)
        selected_method = SELECTION;
    else if(strcmp(method, "insertion") == 0)
        selected_method = INSERTION;
    else if(strcmp(method, "shell") == 0)
        selected_method = SHELL;
    else if(strcmp(method, "quick") == 0)
        selected_method = QUICK;
    else if(strcmp(method, "heap") == 0)
        selected_method = HEAP;
    else
        selected_method = UNDEFINED;
    return selected_method;
}

int get_array_size(char method[]) {
    int size = atoi(method);
    if(size < 0 || size > 1000000)
        size = UNDEFINED;
    return size;
}

int get_array_type(char type[]) {
    int selected_type;
    if(strcmp(type, "random") == 0)
        selected_type = RANDOM_ORDER;
    else if(strcmp(type, "ascending") == 0)
        selected_type = ASCENDING_ORDER;
    else if(strcmp(type, "descending") == 0)
        selected_type = DESCENDING_ORDER;
    else if(strcmp(type, "almost") == 0)
        selected_type = ALMOST_ORDERED;
    else
        selected_type = UNDEFINED;
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
        case SELECTION:
            name = "Selecao";
            break;
        case INSERTION:
            name = "Insercao";
            break;
        case SHELL:
            name = "Shell";
            break;
        case QUICK:
            name = "Quick";
            break;
        case HEAP:
            name = "Heap";
            break;
        case UNDEFINED:
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
        case RANDOM_ORDER:
            name = "Aleatorio";
            break;
        case ASCENDING_ORDER:
            name = "Ordenado";
            break;
        case DESCENDING_ORDER:
            name = "Inversamente ordenado";
            break;
        case ALMOST_ORDERED:
            name = "Quase ordenado";
            break;
        case UNDEFINED:
            name = " - ";
            break;
        default:
            break;
    }
    return name;
}
