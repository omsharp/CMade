#include <stdlib.h>
#include "Utilities.h"

double* copy_array_double(const double arr[], size_t size) {
  double* buffer = malloc(size * sizeof(double));
  Null_Pointer_Guard(buffer, __FILE__, __LINE__);
  for (size_t i = 0; i < size; i++) {
    buffer[i] = arr[i];
  }
  return buffer;
}