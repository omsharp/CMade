#include <unity.h>
#include "Sorting.h"
#include "Stats.h"
#include "Utilities.h"

void setUp(void) {}
void tearDown(void) {}

void test_find_median(void) {
  double values[] = {4.0, 2.0, 1.0, 3.0, 5.0};
  double median = find_median(values, 5);
  TEST_ASSERT_EQUAL_DOUBLE(3, median);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_find_median);

  return UNITY_END();
}
