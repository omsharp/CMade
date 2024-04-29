#include <stdint.h>
#include "Search.h"
#include "Sorting.h"
#include "Stats.h"
#include "Utilities.h"
#include "stdio.h"

#define LEN 5

int main() {
  double values[LEN] = {3.11, 3.41, 3.31, 3.23, 3.01};
  // double array[] = {3.21, 3.41, 3.11, 3.31, 3.01};
  printf("Values: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", values[i]);
  }

  double* copy = copy_array_double(values, LEN);
  printf("\nCopied: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", copy[i]);
  }

  double median = find_median(values, 5);
  printf("\nMedian: %f", median);

  bubble_sort_double(values, LEN);
  printf("\nSorted: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", values[i]);
  }

  int32_t values_int32[LEN] = {33, 434, 23, 66, 6321};
  printf("\nvalues_int32: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%d,  ", values_int32[i]);
  }

  int32_t target = 23;
  int32_t result = binary_search_int32(values_int32, LEN, target);
  if (-1 == result) {
    printf("\nThe value %d was not found in values_int32", target);
  } else {
    printf("\nThe value %d was found in values_int32 at index %d.", target,
           result);
  }
  return EXIT_SUCCESS;
}
