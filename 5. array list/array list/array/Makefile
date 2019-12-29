main : array_main.o array.o
	gcc -o main array_main.o array.o
	clean
array_main.o : array_main.c
	gcc -c array_main.o
array.o : array.c
	gcc -c array.c
clean:
	rm  *.o
