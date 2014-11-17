#include <string.h>

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

int get_sort_method(char method[]) {
    int selected_method;
    printf("%d\n", selected_method);
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

void get_opt(char *argv[], int* method, int* size, int* type) {
    *method = get_sort_method(argv[1]);
    *size   = get_array_size(argv[2]);
    *type   = get_array_type(argv[3]);
}