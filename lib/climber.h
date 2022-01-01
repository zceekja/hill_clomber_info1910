#ifndef CLIMBER_H
#define CLIMBER_H

#include <stddef.h>

///////////////////////////////////////
// MACROS AND VARIABLES
///////////////////////////////////////

#define BYTE char

//////////////////////////////////////
// FUNCTION DECLARATIONS
/////////////////////////////////////


// You want to write this function



int climber(
    int (*hills)(const void*),
    char* (*hills_format)(),
    size_t num_attempts);

int int_algo1(int *a, int* s);
char char_algo1(char* a, char*s);
double double_algo1(double* a, double *s);
int int_algo2(int *a, int* s);
char char_algo2(char* a, char* s);
double double_algo2(double* a, double* s);
void reset(int results[],int* a, char* b, double* c, int* d, char* e, double* f);
int result_check(int results[]);





#endif
