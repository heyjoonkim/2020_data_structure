main : main.o stack.o graph.o search.o queue.o
	gcc -o main main.o graph.o stack.o search.o queue.o
queue.o : queue.c
	gcc -c queue.c
stack.o : stack.c
	gcc -c stack.c
main.o : main.c
	gcc -c main.c
graph.o : graph.c
	gcc -c graph.c
search.o : search.c
	gcc -c search.c
clean :
	rm *o
