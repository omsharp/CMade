#include <stdint.h>
#include <unity.h>
#include "LinkedList.h"

LinkedList* list;

void setUp(void) {
  list = list_new();
}
void tearDown(void) {
  list_destroy(&list);
}

void new_list_should_not_null(void) {
  TEST_ASSERT_NOT_NULL(list);
}

void new_list_length_should_be_zero(void) {
  TEST_ASSERT_EQUAL_INT32(0, list->length);
}

void new_list_head_should_be_null(void) {
  TEST_ASSERT_NULL(list->head);
}

void new_list_tail_should_be_null(void) {
  TEST_ASSERT_NULL(list->tail);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(new_list_should_not_null);
  RUN_TEST(new_list_length_should_be_zero);
  RUN_TEST(new_list_head_should_be_null);
  RUN_TEST(new_list_tail_should_be_null);

  return UNITY_END();
}