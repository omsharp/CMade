#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Guards.h"

void guard_upper_bound(size_t index, size_t upperBound, char *file,
                       size_t line) {
  if (upperBound < index) {
    fprintf(stderr, "Index out of bound!\nfile: %s\nline: %d", file, line);
    exit(EXIT_FAILURE);
  }
}