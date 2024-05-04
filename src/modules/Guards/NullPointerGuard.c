#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Guards.h"

void guard_null_pointer(void *ptr, char *file, size_t line) {
  if (NULL == ptr) {
    fprintf(stderr, "Out of memory error!\nfile: %s\nline: %d", file, line);
    exit(EXIT_FAILURE);
  }
}
