#ifndef __ARRAY_FUNCTIONS__
#define __ARRAY_FUNCTIONS__

// #define define_array_functions(type_in, type_out) \
// \
//   void map(void (*apply)(type_in *, type_out *), type_in *arr, type_out *return_array, int arr_size) { \
//     for (int i = 0; i < arr_size; i++) { \
//       apply(&(arr[i]), &(return_array[i])); \
//     } \
//   }

void map(void (*apply)(void *, void *), void *arr, void *return_arr,
         int arr_size, int member_size, int return_member_size);

int filter(int (*test)(void *), void *arr, void *return_arr, int arr_size,
           int member_size);

void for_each(void (*apply)(void *), void *arr, int arr_size, int member_size);

void concat(void *head_arr, void *tail_arr, void *return_arr, int head_arr_size,
            int tail_arr_size, int member_size);

int index_of(int (*test)(void *), void *arr, int arr_size, int member_size);

int some(int (*test)(void *), void *arr, int arr_size, int member_size);

int every(int (*test)(void *), void *arr, int arr_size, int member_size);

int qsort(int (*compare)(void *, void *), void *arr, int arr_size,
         int member_size);

int msort(int (*compare)(void *, void *), void *arr, int arr_size,
         int member_size);

#endif // __ARRAY_FUNCTIONS__
