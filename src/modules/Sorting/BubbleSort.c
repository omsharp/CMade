#include <stdlib.h>
#include "Sorting.h"

static void swap(double* a, double* b);

void bubbleSort(double arr[], int len) {
  int i, j;
  int isSwapped;
  for (i = 0; i < len - 1; i++) {
    isSwapped = 0;
    for (j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        isSwapped = 1;
      }
    }

    // If no two elements were swapped by inner loop,
    // then break
    if (!isSwapped) break;
  }
}

static void swap(double* a, double* b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}
