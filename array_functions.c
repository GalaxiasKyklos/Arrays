#include "array_functions.h"

void map(void (*apply)(void *, void *), void *arr, void *return_arr, int arr_size, int member_size, int return_member_size) {
  for (int i = 0; i < arr_size; i++) {
    apply(&(arr[i * member_size]), &(return_arr[i * return_member_size]));
  }
}
