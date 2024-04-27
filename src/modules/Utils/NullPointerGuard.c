#include <stdio.h>
#include <stdlib.h>
#include "Utilities.h"

void Null_Pointer_Guard(void *ptr, char *file, int number) {
  if (NULL == ptr) {
    fprintf(stderr, "Out of memory error\nfile: %s\nline: %d", file, number);
    exit(EXIT_FAILURE);
  }
}
