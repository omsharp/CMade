#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include "Guards.h"

LinkedList* list_new() {
  // make the list's head and return it
  LinkedList* head = malloc(sizeof(LinkedList));
  guard_null_pointer(head, __FILE__, __LINE__);
  head->head = NULL;
  head->tail = NULL;  // list has only one node, its first and last.
  head->length = 0;
  return head;
}

void list_append(LinkedList* self, void* newData, size_t sizeOfData) {
  // make the new node
  LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
  guard_null_pointer(newNode, __FILE__, __LINE__);
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->data = malloc(sizeof(sizeOfData));
  guard_null_pointer(newNode->data, __FILE__, __LINE__);

  // copy data
  memcpy(newNode->data, newData, sizeOfData);

  if (self->length < 1) {
    // newNode is the first node
    self->head = newNode;
    self->tail = newNode;
  } else {
    // newNode is not the first node
    newNode->prev = self->tail;
    self->tail->next = newNode;
    self->tail = newNode;
  }
  self->length = self->length + 1;
}

void list_get_data_at(const LinkedList* self, size_t index, void* dataOut,
                      size_t sizeOfData) {
  guard_upper_bound(index, self->length - 1, __FILE__, __LINE__);
  size_t currentIndex = 0;
  LinkedListNode* currentNode = self->head;
  for (;;) {
    if (currentIndex == index) {
      memcpy(dataOut, currentNode->data, sizeOfData);
      break;
    }
    currentIndex++;
    currentNode = currentNode->next;
    if (currentIndex > index || currentNode == NULL) {
      // the upper bound guard shouldn't allow this to happen anyway
      break;
    }
  }
}

void list_set_data_at(const LinkedList* self, size_t index, void* newData,
                      size_t sizeOfData) {
  guard_upper_bound(index, self->length - 1, __FILE__, __LINE__);
  size_t currentIndex = 0;
  LinkedListNode* currentNode = self->head;
  for (;;) {
    if (currentIndex == index) {
      // clean old sapce
      free(currentNode->data);
      currentNode->data = malloc(sizeOfData);
      // copy data
      memcpy(currentNode->data, newData, sizeOfData);
      break;
    }
    currentIndex++;
    currentNode = currentNode->next;
    if (currentIndex > index || currentNode == NULL) {
      // the upper bound guard shouldn't allow this to happen anyway
      break;
    }
  }
}

void list_remove_at(LinkedList* self, size_t index) {
  guard_upper_bound(index, self->length - 1, __FILE__, __LINE__);
  size_t currentIndex = 0;
  LinkedListNode* currentNode = self->head;
  for (;;) {
    if (currentIndex == index) {
      if (currentNode->prev) {
        currentNode->prev->next = currentNode->next;
      }
      if (currentNode->next) {
        currentNode->next->prev = currentNode->prev;
      }
      free(currentNode->data);
      free(currentNode);
      self->length = self->length - 1;
      break;
    }
    currentIndex++;
    if (currentIndex > index) {
      // the upper bound guard shouldn't allow this to happen anyway
      break;
    }
    currentNode = currentNode->next;
  }
}

void list_destroy(LinkedList** self) {
  LinkedListNode* currentNode = (*self)->head;
  while (currentNode) {
    LinkedListNode* next = currentNode->next;
    free(currentNode->data);
    free(currentNode);
    currentNode = next;
  }
  free(*self);
  *self = NULL;
}