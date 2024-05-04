#include <stdint.h>
#include <unity.h>
#include "LinkedList.h"
#include "stdlib.h"

// random data
#define DATA_0 "data_0_gaadsf"
#define DATA_1 "data_1_kdjgh"
#define DATA_2 "data_2_sd"
#define DATA_3 "data_3_akdsjfa;skdjf"
#define DATA_4 "data_4_fadsfkjk"
#define DATA_5 "data_5_fag"
#define DATA_6 "data_6"

LinkedList* list;

void setUp(void) {
  list = list_new();
}
void tearDown(void) {
  list_destroy(&list);
}

void should_have_correct_length_after_append(void) {
  size_t originalLength = list->length;
  list_append(list, DATA_1, sizeof(DATA_1));
  TEST_ASSERT_EQUAL_INT32(originalLength + 1, list->length);

  list_append(list, DATA_2, sizeof(DATA_2));
  TEST_ASSERT_EQUAL_INT32(originalLength + 2, list->length);

  list_append(list, DATA_3, sizeof(DATA_3));
  TEST_ASSERT_EQUAL_INT32(originalLength + 3, list->length);
}

void tail_should_point_to_latest_node(void) {
  list_append(list, DATA_1, sizeof(DATA_1));
  TEST_ASSERT_EQUAL_STRING(DATA_1, list->tail->data);

  list_append(list, DATA_2, sizeof(DATA_2));
  TEST_ASSERT_EQUAL_STRING(DATA_2, list->tail->data);

  list_append(list, DATA_3, sizeof(DATA_3));
  TEST_ASSERT_EQUAL_STRING(DATA_3, list->tail->data);
}

void should_have_correct_nodes_order(void) {
  list_append(list, DATA_1, sizeof(DATA_1));
  list_append(list, DATA_2, sizeof(DATA_2));
  list_append(list, DATA_3, sizeof(DATA_3));
  list_append(list, DATA_4, sizeof(DATA_4));

  TEST_ASSERT_EQUAL_STRING(DATA_1, list->head->data);
  TEST_ASSERT_EQUAL_STRING(DATA_2, list->head->next->data);
  TEST_ASSERT_EQUAL_STRING(DATA_3, list->head->next->next->data);
  TEST_ASSERT_EQUAL_STRING(DATA_4, list->head->next->next->next->data);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(should_have_correct_length_after_append);
  RUN_TEST(tail_should_point_to_latest_node);
  RUN_TEST(should_have_correct_nodes_order);

  return UNITY_END();
}