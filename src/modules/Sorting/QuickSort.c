#include <stdlib.h>
#include "Sorting.h"

static void swap(double* a, double* b);
static int partition(double arr[], size_t low, size_t high);

void quickSort(double arr[], size_t low, size_t high) {
  if (low < high) {
    size_t pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

static int partition(double arr[], size_t low, size_t high) {
  double pivot = arr[high];
  size_t i = low - 1;
  for (size_t j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

static void swap(double* a, double* b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}
