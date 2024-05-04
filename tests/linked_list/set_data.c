#include <stdint.h>
#include <string.h>
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

void set_data_should_not_change_length(void) {
  size_t originalLength = list->length;

  size_t dataSize = strlen(DATA_5);
  list_set_data_at(list, 3, &DATA_5, dataSize);
  TEST_ASSERT_EQUAL_INT32(originalLength, list->length);

  dataSize = strlen(DATA_1);
  list_set_data_at(list, 5, &DATA_1, dataSize);
  TEST_ASSERT_EQUAL_INT32(originalLength, list->length);

  dataSize = strlen(DATA_6);
  list_set_data_at(list, 1, &DATA_6, dataSize);
  TEST_ASSERT_EQUAL_INT32(originalLength, list->length);
}

void set_data_should_change_correct_node(void) {
  size_t index = 3;
  char* newData1 = "new_data_1_other_stuff";
  size_t dataSize = strlen(newData1);
  list_set_data_at(list, index, newData1, dataSize);
  char* currentData = malloc(30);
  list_get_data_at(list, index, currentData, dataSize);
  TEST_ASSERT_EQUAL_MEMORY(newData1, currentData, dataSize);

  index = 4;
  char* newData2 = "new_data_2_stuff";
  dataSize = strlen(newData2);
  list_set_data_at(list, index, newData2, dataSize);
  list_get_data_at(list, index, currentData, dataSize);
  TEST_ASSERT_EQUAL_MEMORY(newData2, currentData, dataSize);

  index = 1;
  char* newData3 = "new_data_3_more_stuff_stuff";
  dataSize = strlen(newData3);
  list_set_data_at(list, index, newData3, dataSize);
  list_get_data_at(list, index, currentData, dataSize);
  TEST_ASSERT_EQUAL_MEMORY(newData3, currentData, dataSize);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(set_data_should_not_change_length);
  RUN_TEST(set_data_should_change_correct_node);

  return UNITY_END();
}