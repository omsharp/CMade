#include "Sorting.h"
#include "Stats.h"
#include "stdio.h"

#define LEN 5

int main() {
  double values[LEN] = {3.21, 3.41, 3.11, 3.31, 3.01};
  // double array[] = {3.21, 3.41, 3.11, 3.31, 3.01};
  printf("Values: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", values[i]);
  }

  printf("\nMedian: %f", find_median(values, 5));

  quickSort(values, 0, LEN - 1);
  printf("\nSorted: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", values[i]);
  }

  return EXIT_SUCCESS;
}
