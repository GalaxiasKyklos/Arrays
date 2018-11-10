#include <stdio.h>
#include "arrays.h"

void plus_one(void *a, void *b) {
  char *ai = a;
  int *bi = b;
  *bi = (int) *ai;
}

int main(void) {
  char cosa[] = {'a','b','c'};
  print_char_array(cosa, 3);

  int cosa2[3];
  map(plus_one, cosa, cosa2, 3, sizeof (char), sizeof (int));

  print_int_array(cosa2, 3);
  return 0;
}
