#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

typedef struct Student {
  size_t id;
  char* name;
} Student;

int main() {
  LinkedList* list = list_new();

  printf("------------------------ \n");
  printf("appending: \n");
  for (size_t i = 1; i <= 10; i++) {
    char* name = malloc(sizeof(char) * 12);
    snprintf(name, 12, "Student-%zu", i);
    Student temp = {.id = i, .name = name};
    printf("id: %zu | name: %s\n", temp.id, temp.name);
    list_append(list, &temp, sizeof(Student));
  }
  printf("------------------------ \n");
  printf("%zu students added\n", list->length);
  printf("------------------------ \n");

  // --------- change some data ------------
  // Student* st = list_get_data_at(list, 3);
  // Student ns = {.id = 23, .name = "new name"};
  // st = &ns;
  // --------- data changed ------------

  printf("printing: \n");
  LinkedListNode* currentNode = list->head;
  while (currentNode) {
    Student* s = currentNode->data;
    printf("id: %zu | name: %s\n", s->id, s->name);
    currentNode = currentNode->next;
  }
  printf("------------------------ \n");

  printf("------ get data ------------ \n");
  void* dataOut = malloc(sizeof(Student));
  list_get_data_at(list, 3, dataOut, sizeof(Student));
  printf("dataOut: %s\n", ((Student*)dataOut)->name);

  // size_t index = 3;
  // Student* data = list_data_ref_at(list, index);
  // printf("data at index %zu is:\n", index);
  // printf("id: %zu | name: %s\n", data->id, data->name);
  // printf("------------------------ \n");

  // list_remove_at(list, index);
  // Student* data2 = list_data_ref_at(list, index);
  // printf("length after removing one node: %zu\n", list->length);
  // printf("data at index %zu now is:\n", index);
  // printf("id: %zu | name: %s\n", data2->id, data2->name);
  // printf("------------------------ \n");

  // list_destroy(&list);

  // printf(list == NULL ? "null" : "not null");
  return 0;
}