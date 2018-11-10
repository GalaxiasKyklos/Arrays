all: arrays main clean

arrays: print_arrays array_functions lib_arrays

print_arrays:
	clang -c print_arrays.c

array_functions:
	clang -c array_functions.c

lib_arrays:
	ar cr /usr/local/clib/libarrays.a print_arrays.o array_functions.o

main:
	clang -o main main.c -larrays

clean:
	rm -f *.o
