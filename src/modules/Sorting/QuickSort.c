#include <stdlib.h>
#include "Sorting.h"

static void swap(double* a, double* b);
static int partition(double arr[], int low, int high);

void quickSort(double arr[], size_t low, size_t high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int partition(double arr[], int low, int high) {
  // initialize pivot to be the first element
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    // condition 1: find the first element greater than
    // the pivot (from starting)
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }

    // condition 2: find the first element smaller than
    // the pivot (from last)
    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);
  return j;
}

static void swap(double* a, double* b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}
