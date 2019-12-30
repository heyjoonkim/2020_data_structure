main: main.o postfix.o
	gcc -o main main.o postfix.o
main.o : main.c
	gcc -c main.c
postfix.o : postfix.c
	gcc -c postfix.c
clean:
	rm *.o
