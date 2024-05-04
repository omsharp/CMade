#include <stdint.h>
#include <string.h>
#include <unity.h>
#include "LinkedList.h"

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
  list_append(list, DATA_0, sizeof(DATA_0));
  list_append(list, DATA_1, sizeof(DATA_1));
  list_append(list, DATA_2, sizeof(DATA_2));
  list_append(list, DATA_3, sizeof(DATA_3));
  list_append(list, DATA_4, sizeof(DATA_4));
  list_append(list, DATA_5, sizeof(DATA_5));
  list_append(list, DATA_6, sizeof(DATA_6));
}

void tearDown(void) {
  list_destroy(&list);
}

void should_have_correct_length_after_remove(void) {
  size_t originalLength = list->length;
  list_remove_at(list, list->length - 4);
  TEST_ASSERT_EQUAL_INT32(originalLength - 1, list->length);

  list_remove_at(list, list->length - 1);
  TEST_ASSERT_EQUAL_INT32(originalLength - 2, list->length);

  list_remove_at(list, list->length - 3);
  TEST_ASSERT_EQUAL_INT32(originalLength - 3, list->length);
}

void should_remove_the_correct_node(void) {
  size_t removeIndex = 4;
  size_t dataSize = strlen(DATA_4);
  char* removedData = malloc(dataSize);
  list_get_data_at(list, removeIndex, removedData, dataSize);
  list_remove_at(list, removeIndex);
  LinkedListNode* currentNode = list->head;
  while (currentNode) {
    TEST_ASSERT_NOT_EQUAL_MESSAGE(removedData, currentNode->data,
                                  "Removed a wrong node!");
    currentNode = currentNode->next;
  }
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(should_have_correct_length_after_remove);
  RUN_TEST(should_remove_the_correct_node);

  return UNITY_END();
}