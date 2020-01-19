#include "priority_queue.h"
#include <stdio.h>

int main(void) {
	Heap h;

	init(&h, 100);

	add(&h, 2);
	add(&h, 1);
	add(&h, 4);
	add(&h, 5);
	add(&h, 3);
	add(&h, 7);
	add(&h, 6);
	add(&h, 9);

	print(&h);

	Element i = removeItem(&h);
	printf("* removed : %d\n", i);
	print(&h);

	i = removeItem(&h);
	printf("* removed : %d\n", i);
	print(&h);

	i = removeItem(&h);
	printf("* removed : %d\n", i);
	print(&h);

	i = removeItem(&h);
	printf("* removed : %d\n", i);
	print(&h);

	i = removeItem(&h);
	printf("* removed : %d\n", i);
	print(&h);

	add(&h, 10);
	print(&h);
}
