#include "Sorting.h"
#include "Stats.h"
#include "stdio.h"

#define LEN 4

int main() {
  double values[LEN] = {142.0, -5.0, 734.0, 5.0};
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
