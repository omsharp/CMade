#include "ModuleA.h"
#include "ModuleB.h"
#include "stdio.h"

int main() {
  int values[5] = {142, -5, 734, 5, 44};
  printf("  values: %d, %d, %d, %d, %d\n", values[0], values[1], values[2],
         values[3], values[4]);
  printf(" largest: %d\n", find_max_int(values, 5));
  printf("smallest: %d\n", find_min_int(values, 5));
  return EXIT_SUCCESS;
}
