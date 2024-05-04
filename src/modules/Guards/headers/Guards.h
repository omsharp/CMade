#ifndef GUARDS_H
#define GUARDS_H

#include <stdint.h>
#include <stdlib.h>

void guard_null_pointer(void *ptr, char *file, size_t line);

void guard_upper_bound(size_t index, size_t upperBound, char *file,
                       size_t line);

#endif