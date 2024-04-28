#include "Sorting.h"
#include "Stats.h"
#include "stdio.h"

#define LEN 5

int main() {
  double values[LEN] = {3.11, 3.41, 3.31, 3.22, 3.01};
  // double array[] = {3.21, 3.41, 3.11, 3.31, 3.01};
  printf("Values: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", values[i]);
  }

  double median = find_median(values, 5);
  printf("\nMedian: %f", median);

  bubbleSort(values, LEN);
  printf("\nSorted: ");
  for (size_t i = 0; i < LEN; i++) {
    printf("%f,  ", values[i]);
  }

  return EXIT_SUCCESS;
}
