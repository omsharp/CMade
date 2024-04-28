#include "stdlib.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void some_test(void) {
  TEST_ASSERT_EQUAL_STRING_LEN("hello", "hello", 5);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(some_test);

  return UNITY_END();
}
