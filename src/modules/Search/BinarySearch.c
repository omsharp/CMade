#include <stdlib.h>
#include "Search.h"

int32_t binary_search_int32(int32_t* arr, size_t len, int32_t target) {
  int32_t left = 0;
  int32_t right = len - 1;
  while (left <= right) {
    int32_t mid = left + (right - left) / 2;

    // Check if target is present at mid
    if (arr[mid] == target) {
      return mid;
    }

    // If target is greater, ignore left half
    if (arr[mid] < target) {
      left = mid + 1;
    }
    // If target is smaller, ignore right half
    else {
      right = mid - 1;
    }
  }

  // If target is not found in the array
  return -1;
}