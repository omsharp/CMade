#include <stdbool.h>
#include <stdlib.h>
#include "SortUtils.h"
#include "Sorting.h"

void bubble_sort_double(double arr[], size_t len) {
  size_t i, j;
  bool isSwapped = false;
  for (i = 0; i < len - 1; i++) {
    isSwapped = 0;
    for (j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap_double(&arr[j], &arr[j + 1]);
        isSwapped = true;
      }
    }

    // If no two elements were swapped by inner loop,
    // then break
    if (!isSwapped) break;
  }
}

void bubble_sort_int32(int32_t arr[], size_t len) {
  size_t i, j;
  bool isSwapped = false;
  for (i = 0; i < len - 1; i++) {
    isSwapped = 0;
    for (j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap_int32(&arr[j], &arr[j + 1]);
        isSwapped = true;
      }
    }

    // If no two elements were swapped by inner loop,
    // then break
    if (!isSwapped) break;
  }
}
