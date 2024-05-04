#include <stdint.h>
#include <unity.h>
#include "LinkedList.h"

LinkedList* list;

void setUp(void) {}
void tearDown(void) {}

void freed_list_should_be_null(void) {
  LinkedList* list = list_new();
  list_destroy(&list);
  TEST_ASSERT_NULL(list);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(freed_list_should_be_null);

  return UNITY_END();
}