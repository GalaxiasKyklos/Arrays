#include "array_functions.h"
#include <string.h>

void map(void (*apply)(void *, void *), void *arr, void *return_arr,
         int arr_size, int member_size, int return_member_size) {
  for (int i = 0; i < arr_size; i++) {
    apply(&(arr[i * member_size]), &(return_arr[i * return_member_size]));
  }
}

void for_each(void (*apply)(void *), void *arr, int arr_size, int member_size) {
  for (int i = 0; i < arr_size; i++) {
    apply(&(arr[i * member_size]));
  }
}

int filter(int (*test)(void *), void *arr, void *return_arr, int arr_size,
           int member_size) {
  int cont = 0;
  for (int i = 0; i < arr_size; i++) {
    if (test(&(arr[i * member_size]))) {
      memmove(return_arr + cont++ * member_size, arr + i * member_size,
              member_size);
    }
  }
  return cont;
}
