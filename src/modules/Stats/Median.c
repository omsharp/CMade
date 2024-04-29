#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorting.h"
#include "Stats.h"
#include "Utilities.h"

double find_median(const double* values, size_t len) {
  // copy values array
  double* temp = copy_array_double(values, len);
  // sort the copied array
  bubble_sort_double(temp, len);
  // find median
  double median = 0;
  if (len % 2 == 0) {
    // even
    median = (temp[(len / 2) - 1] + temp[(len / 2)]) / 2.0;
  } else {
    // odd
    median = temp[((len + 1) / 2) - 1];
  }
  // free the copied array
  free(temp);
  // return median
  return median;
}
