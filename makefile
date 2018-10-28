all: arrays main clean

arrays: print_arrays lib_arrays

print_arrays:
	clang -c print_arrays.c

lib_arrays:
	ar cr /usr/local/clib/libarrays.a print_arrays.o

main:
	clang -o main main.c -larrays

clean:
	rm -f *.o
