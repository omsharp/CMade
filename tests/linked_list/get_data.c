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

void should_return_correct_data(void) {
  size_t index = 4;
  size_t dataSize = strlen(DATA_4);
  char* currentData = malloc(dataSize);
  list_get_data_at(list, index, currentData, dataSize);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(DATA_4, currentData, "Returned wrong data.");
  free(currentData);

  index = 5;
  dataSize = strlen(DATA_5);
  currentData = malloc(dataSize);
  list_get_data_at(list, index, currentData, dataSize);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(DATA_5, currentData, "Returned wrong data.");
  free(currentData);

  index = 1;
  dataSize = strlen(DATA_1);
  currentData = malloc(dataSize);
  list_get_data_at(list, index, currentData, dataSize);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(DATA_1, currentData, "Returned wrong data.");
  free(currentData);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(should_return_correct_data);

  return UNITY_END();
}