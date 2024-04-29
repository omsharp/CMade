#include "SortUtils.h"
#include <stdint.h>

void swap_double(double* a, double* b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

void swap_int32(int32_t* a, int32_t* b) {
  int32_t temp = *a;
  *a = *b;
  *b = temp;
}
