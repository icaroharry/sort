/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/30/2014 04:10:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef GET_OPT
#define GET_OPT

#include "array.h"
#include "sort.h"

int check_opt(int argc);
int get_sort_method(char method[]);
int get_array_size(char method[]);
int get_array_type(char type[]);
void get_opt(int argc, char **argv, int *method, int *size, int *array_type, int *print_vector);
char* get_method_name(int method);
char* get_array_type_name(int type);

#endif
