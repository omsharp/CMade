#include <Sorting.h>
#include <Stats.h>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

void test_BubbleSort_Double(void) {
  double array[] = {3.0, 0, 4.0, 1.0, 2.0};
  double m = find_median(array, 5);
  bubbleSort(array, 5);
  TEST_ASSERT_EQUAL_DOUBLE(0, array[0]);
  TEST_ASSERT_EQUAL_DOUBLE(1, array[1]);
  TEST_ASSERT_EQUAL_DOUBLE(2, array[2]);
  TEST_ASSERT_EQUAL_DOUBLE(3, array[3]);
  TEST_ASSERT_EQUAL_DOUBLE(4, array[4]);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_BubbleSort_Double);

  return UNITY_END();
}