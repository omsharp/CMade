#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

typedef struct LinkedListNode {
  struct LinkedListNode* prev;
  struct LinkedListNode* next;
  void* data;
} LinkedListNode;

typedef struct LinkedList {
  struct LinkedListNode* head;  // first node in list
  struct LinkedListNode* tail;  // last node in list
  size_t length;                // number of nodes in list
} LinkedList;

LinkedList* list_new();

void list_append(LinkedList* self, void* data, size_t sizeOfData);

void list_get_data_at(const LinkedList* self, size_t index, void* dataOut,
                      size_t sizeOfData);

void list_set_data_at(const LinkedList* self, size_t index, void* data,
                      size_t sizeOfData);

void list_remove_at(LinkedList* self, size_t index);

void list_destroy(LinkedList** self);

void list_print(const LinkedList* self);

#endif