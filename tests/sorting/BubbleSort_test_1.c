#include <SortUtils.h>
#include <Sorting.h>
#include <Stats.h>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

void test_BubbleSort_Double(void) {
  double array[] = {3.0, 0, 4.0, 1.0, 2.0};
  bubble_sort_double(array, 5);
  TEST_ASSERT_EQUAL_DOUBLE(0, array[0]);
  TEST_ASSERT_EQUAL_DOUBLE(1, array[1]);
  TEST_ASSERT_EQUAL_DOUBLE(2, array[2]);
  TEST_ASSERT_EQUAL_DOUBLE(3, array[3]);
  TEST_ASSERT_EQUAL_DOUBLE(4, array[4]);

  // checking if mdoules/headers linking correctly
  // (has nothing to do with curent test)
  double m = find_median(array, 5);
  double av = 32;
  double bv = 32;
  double* ap = &av;
  double* bp = &bv;
  swap_double(ap, bp);
  // end ----------------------
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_BubbleSort_Double);

  return UNITY_END();
}