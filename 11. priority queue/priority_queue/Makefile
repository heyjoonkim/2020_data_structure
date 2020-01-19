main : main.o priority_queue.o
	gcc -o main main.o priority_queue.o
main.o : main.c
	gcc -c main.c
priority_queue.o : priority_queue.c
	gcc -c priority_queue.c
clean:
	rm *.o
