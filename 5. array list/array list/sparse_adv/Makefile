main : main.o sparse.o
	gcc -o main main.o sparse.o
main.o : main.c
	gcc -c main.c
sparse.o : sparse.c
	gcc -c sparse.c
clean : 
	rm *.o
