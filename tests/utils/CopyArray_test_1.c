#include <unity.h>
#include "Utilities.h"

#define LEN_FOUR 4

void setUp(void) {}
void tearDown(void) {}

void copy_array_double_should_return_something(void) {
  double source[LEN_FOUR] = {1.0, 2.0, 3.0, 4.0};
  double* copy = copy_array_double(source, LEN_FOUR);
  TEST_ASSERT_NOT_NULL(copy);
}

void copy_array_double_should_return_different_pointer(void) {
  double source[LEN_FOUR] = {5.4, 12, 632, 73.5};
  double* copy = copy_array_double(source, 4);
  TEST_ASSERT_NOT_EQUAL(source, copy);
}

void copy_array_double_should_copy_correct_values(void) {
  double source[LEN_FOUR] = {5.4, 12, 632, 73.5};
  double* copy = copy_array_double(source, 4);
  TEST_ASSERT_EQUAL_DOUBLE(source[0], copy[0]);
  TEST_ASSERT_EQUAL_DOUBLE(source[1], copy[1]);
  TEST_ASSERT_EQUAL_DOUBLE(source[2], copy[2]);
  TEST_ASSERT_EQUAL_DOUBLE(source[3], copy[3]);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(copy_array_double_should_return_something);
  RUN_TEST(copy_array_double_should_copy_correct_values);
  RUN_TEST(copy_array_double_should_return_different_pointer);

  return UNITY_END();
}
