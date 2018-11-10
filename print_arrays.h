#ifndef __PRINT_ARRAYS__
#define __PRINT_ARRAYS__

int from_char(void *member, char *buffer);
int from_double(void *member, char *buffer);
int from_float(void *member, char *buffer);
int from_int(void *member, char *buffer);
int from_long_double(void *member, char *buffer);
int from_long_int(void *member, char *buffer);
int from_long_long_int(void *member, char *buffer);
int from_short_int(void *member, char *buffer);
int from_unsigned_int(void *member, char *buffer);
int from_unsigned_long_int(void *member, char *buffer);
int from_unsigned_long_long_int(void *member, char *buffer);
int from_unsigned_short_int(void *member, char *buffer);

void print_array(int (*to_string)(void *, char *), char *buffer, void *arr, int arr_size, int member_size);

void print_char_array(char *array, int size);
void print_double_array(double *array, int size);
void print_float_array(float *array, int size);
void print_int_array(int *array, int size);
void print_long_double_array(long double *array, int size);
void print_long_int_array(long int *array, int size);
void print_long_long_int_array(long long int *array, int size);
void print_short_int_array(short int *array, int size);
void print_unsigned_int_array(unsigned int *array, int size);
void print_unsigned_long_int_array(unsigned long int *array, int size);
void print_unsigned_long_long_int_array(unsigned long long int *array, int size);
void print_unsigned_short_int_array(unsigned short int *array, int size);

#endif // __PRINT_ARRAYS__
