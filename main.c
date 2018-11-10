#include "arrays.h"
#include <stdio.h>

#define ARR_SIZE 4

void to_int(void *a, void *b) {
  char *ap = a;
  int *bp = b;
  *bp = (int)*ap;
}

int is_a(void *a) {
  int *ap = a;
  return *ap == 'a';
}

void plus_one(void *a) {
  int *ap = a;
  *ap += 1;
}

int main(void) {
  char cosa[ARR_SIZE] = {'a', 'b', 'c', 'a'};
  print_char_array(cosa, ARR_SIZE);

  int cosa2[ARR_SIZE];
  map(to_int, cosa, cosa2, ARR_SIZE, sizeof(char), sizeof(int));
  print_int_array(cosa2, ARR_SIZE);

  int cosa3[ARR_SIZE];
  int size = filter(is_a, cosa2, cosa3, ARR_SIZE, sizeof(int));
  print_int_array(cosa3, size);

  for_each(plus_one, cosa2, ARR_SIZE, sizeof(int));
  print_int_array(cosa2, ARR_SIZE);

  int cosa4[ARR_SIZE + size];
  concat(cosa2, cosa3, cosa4, ARR_SIZE, size, sizeof(int));
  print_int_array(cosa4, ARR_SIZE + size);
  return 0;
}
