#include "print_arrays.h"
#include <stdio.h>

char _native_buffer[20];

int from_char(void *member, char *buffer) {
  return sprintf(buffer, "%c", *((char *)member));
}

int from_double(void *member, char *buffer) {
  return sprintf(buffer, "%lf", *((double *)member));
}

int from_float(void *member, char *buffer) {
  return sprintf(buffer, "%f", *((float *)member));
}

int from_int(void *member, char *buffer) {
  return sprintf(buffer, "%d", *((int *)member));
}

int from_long_double(void *member, char *buffer) {
  return sprintf(buffer, "%Lf", *((long double *)member));
}

int from_long_int(void *member, char *buffer) {
  return sprintf(buffer, "%ld", *((long int *)member));
}

int from_long_long_int(void *member, char *buffer) {
  return sprintf(buffer, "%lld", *((long long int *)member));
}

int from_short_int(void *member, char *buffer) {
  return sprintf(buffer, "%hd", *((short int *)member));
}

int from_unsigned_int(void *member, char *buffer) {
  return sprintf(buffer, "%u", *((unsigned int *)member));
}

int from_unsigned_long_int(void *member, char *buffer) {
  return sprintf(buffer, "%lu", *((unsigned long int *)member));
}

int from_unsigned_long_long_int(void *member, char *buffer) {
  return sprintf(buffer, "%llu", *((unsigned long long int *)member));
}

int from_unsigned_short_int(void *member, char *buffer) {
  return sprintf(buffer, "%hu", *((unsigned short int *)member));
}

void print_array(int (*to_string)(void *, char *), char *buffer, void *arr,
                 int arr_size, int member_size) {
  printf("[");
  for (int i = 0; i < arr_size; i++) {
    to_string(&(arr[i * member_size]), buffer);
    printf("%s", buffer);
    if (i + 1 < arr_size) {
      printf(", ");
    }
  }
  printf("]\n");
}

void print_char_array(char *array, int size) {
  print_array(from_char, _native_buffer, array, size, sizeof(char));
}

void print_double_array(double *array, int size) {
  print_array(from_double, _native_buffer, array, size, sizeof(double));
}

void print_float_array(float *array, int size) {
  print_array(from_float, _native_buffer, array, size, sizeof(float));
}

void print_int_array(int *array, int size) {
  print_array(from_int, _native_buffer, array, size, sizeof(int));
}

void print_long_double_array(long double *array, int size) {
  print_array(from_long_double, _native_buffer, array, size,
              sizeof(long double));
}

void print_long_int_array(long int *array, int size) {
  print_array(from_long_int, _native_buffer, array, size, sizeof(long int));
}

void print_long_long_int_array(long long int *array, int size) {
  print_array(from_long_long_int, _native_buffer, array, size,
              sizeof(long long int));
}

void print_short_int_array(short int *array, int size) {
  print_array(from_short_int, _native_buffer, array, size, sizeof(short int));
}

void print_unsigned_int_array(unsigned int *array, int size) {
  print_array(from_unsigned_int, _native_buffer, array, size,
              sizeof(unsigned int));
}

void print_unsigned_long_int_array(unsigned long int *array, int size) {
  print_array(from_unsigned_long_int, _native_buffer, array, size,
              sizeof(unsigned long int));
}

void print_unsigned_long_long_int_array(unsigned long long int *array,
                                        int size) {
  print_array(from_unsigned_long_long_int, _native_buffer, array, size,
              sizeof(unsigned long long int));
}

void print_unsigned_short_int_array(unsigned short int *array, int size) {
  print_array(from_unsigned_short_int, _native_buffer, array, size,
              sizeof(unsigned short int));
}
