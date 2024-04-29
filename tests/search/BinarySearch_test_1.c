#include <stdint.h>
#include <unity.h>
#include "Search.h"

void setUp(void) {}
void tearDown(void) {}

void test_binary_search_int32_not_found(void) {
  int32_t array[] = {1, 2, 3, 4, 5};
  int32_t result = binary_search_int32(array, 5, 234);
  TEST_ASSERT_EQUAL_INT32(-1, result);
}

void test_binary_search_int32_correct_result(void) {
  int32_t array[] = {1, 2, 3, 4, 5};
  int32_t result = binary_search_int32(array, 5, array[3]);
  TEST_ASSERT_EQUAL_INT32(3, result);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_binary_search_int32_not_found);
  RUN_TEST(test_binary_search_int32_correct_result);

  return UNITY_END();
}