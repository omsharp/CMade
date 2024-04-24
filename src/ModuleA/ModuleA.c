#include "ModuleA.h"
#include <stdlib.h>

int find_max_int(const int *array, size_t len) {
  int result = *array;
  for (int i = 1; i < len; i++) {
    if (array[i] > result) {
      result = array[i];
    }
  }
  return result;
}
