#include <unity.h>
#include "Utilities.h"

void setUp(void) {}
void tearDown(void) {}

void copy_array_double_should_return_something(void) {
  double original[] = {1.0, 2.0, 3.0, 4.0};
  double* copy = copy_array_double(original, 4);
  TEST_ASSERT_NOT_NULL(copy);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(copy_array_double_should_return_something);

  return UNITY_END();
}
