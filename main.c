#include "arrays.h"
#include <stdio.h>

#define ARR_SIZE 4

void to_int(void *a, void *b) {
  char *ap = a;
  int *bp = b;
  *bp = (int)*ap;
}

void to_char(void *a, void *b) {
  int *ap = a;
  char *bp = b;
  *bp = (char)*ap;
}

int is_a(void *a) {
  int *ap = a;
  return *ap == 'a';
}

int is_c(void *a) {
  char *ap = a;
  return *ap == 'c';
}

void to_c(void *a) {
  char *ap = a;
  *ap = 'c';
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

  printf("c is at index %d in ", index_of(is_c, cosa, ARR_SIZE, sizeof(char)));
  print_char_array(cosa, ARR_SIZE);

  if (some(is_c, cosa, ARR_SIZE, sizeof(char))) {
    printf("some c in ");
    print_char_array(cosa, ARR_SIZE);
  }

  char cosa5[size];
  for_each(to_c, cosa5, size, sizeof(char));

  if (every(is_c, cosa5, size, sizeof(char))) {
    printf("only c in ");
    print_char_array(cosa5, size);
  }

  if (!every(is_c, cosa, ARR_SIZE, sizeof(char))) {
    printf("not all are c in ");
    print_char_array(cosa, ARR_SIZE);
  }

  return 0;
}
