#include <unity.h>
#include "Sorting.h"
#include "Stats.h"
#include "Utilities.h"

void setUp(void) {}
void tearDown(void) {}

void test_find_median(void) {
  double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  TEST_ASSERT_EQUAL_DOUBLE(3, find_median(values, 5));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_find_median);

  return UNITY_END();
}
