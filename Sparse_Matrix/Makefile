sparse_array:sparse_array.o
  gcc -o sparse_array sparse_array.o

sparse_array.o:sparse_array.c
  gcc -c -g -Wall -o sparse_array.o sparse_array.c

clean:
  rm -rf sparse_array.o
  rm -rf sparse_array

valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./sparse_array
