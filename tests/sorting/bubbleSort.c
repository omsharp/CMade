#include <Sorting.h>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

void test_BubbleSort_Double_1(void) {
  double array[] = {3.0, 0, 4.0, 1.0, 2.0};
  bubbleSort(array, 5);
  TEST_ASSERT_EQUAL_DOUBLE(0, array[0]);
  TEST_ASSERT_EQUAL_DOUBLE(1, array[1]);
  TEST_ASSERT_EQUAL_DOUBLE(2, array[2]);
  TEST_ASSERT_EQUAL_DOUBLE(3, array[3]);
  TEST_ASSERT_EQUAL_DOUBLE(4, array[4]);
}

void test_BubbleSort_Double_2(void) {
  double array[] = {3.21, 3.41, 3.11, 3.31, 3.01};
  bubbleSort(array, 5);
  TEST_ASSERT_EQUAL_DOUBLE(3.0, array[0]);
  TEST_ASSERT_EQUAL_DOUBLE(3.1, array[1]);
  TEST_ASSERT_EQUAL_DOUBLE(3.2, array[2]);
  TEST_ASSERT_EQUAL_DOUBLE(3.3, array[3]);
  TEST_ASSERT_EQUAL_DOUBLE(3.4, array[4]);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_BubbleSort_Double_1);
  RUN_TEST(test_BubbleSort_Double_2);

  return UNITY_END();
}