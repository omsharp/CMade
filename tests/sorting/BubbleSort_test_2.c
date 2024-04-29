#include <Sorting.h>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

void test_BubbleSort_Double(void) {
  double array[] = {3.21, 3.41, 3.11, 3.31, 3.01};
  bubble_sort_double(array, 5);
  TEST_ASSERT_EQUAL_DOUBLE(3.01, array[0]);
  TEST_ASSERT_EQUAL_DOUBLE(3.11, array[1]);
  TEST_ASSERT_EQUAL_DOUBLE(3.21, array[2]);
  TEST_ASSERT_EQUAL_DOUBLE(3.31, array[3]);
  TEST_ASSERT_EQUAL_DOUBLE(3.41, array[4]);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_BubbleSort_Double);

  return UNITY_END();
}