#include "arrays.h"
#include <stdio.h>

void plus_one(void *a, void *b) {
  char *ai = a;
  int *bi = b;
  *bi = (int)*ai;
}

int is_a(void *a) {
  int *ac = (int *)a;
  return *ac == 'a';
}

int main(void) {
  char cosa[] = {'a', 'b', 'c', 'a'};
  print_char_array(cosa, 4);

  int cosa2[4];
  map(plus_one, cosa, cosa2, 4, sizeof(char), sizeof(int));
  print_int_array(cosa2, 4);

  int cosa3[4];
  int size = filter(is_a, cosa2, cosa3, 4, sizeof(int));
  print_int_array(cosa3, size);
  return 0;
}
