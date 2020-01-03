main : main.o tree.o
	gcc -o main main.o tree.o
main.o : main.c
	gcc -c main.c
tree.o : tree.c
	gcc -c tree.c
clean : 
	rm *.o
