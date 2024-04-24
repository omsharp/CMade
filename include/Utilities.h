#ifndef UTILS_H
#define UTILS_H
#include "stdlib.h"

void Null_Pointer_Guard(void *ptr, char *file, int number);

double *copy_array_double(const double arr[], size_t size);

#endif