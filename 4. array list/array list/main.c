#include <stdio.h>
#include "array.h"

int main(void) {
	Array a;
	init(&a, 10);
	printf("%3d %3d\n", a.size, a.max);
	printf("isEmpty : %d, isFull : %d\n", isEmpty(&a), isFull(&a));
	print(&a);

	append(&a, 1);
	append(&a, 2);
	append(&a, 3);
	print(&a);

	removeItem(&a, 3);
	print(&a);

	addAt(&a, 8, 0);
	print(&a);

	removeItem(&a, 1);
	append(&a, 13);
	append(&a, 32);
	append(&a, 37);
	append(&a, 5);
	append(&a, 21);
	print(&a);

	printf("index of %d : %d\n", 2, linearSearch(&a, 2));

	Array b;
	copyArray(&a, &b);
	print(&b);
	selectionSort(&b);
	print(&b);

	copyArray(&a, &b);
	print(&b);
	printf("* quick sort\n");
	quickSort(&b, 0, b.size-1);
	print(&b);

	printf("index of %d : %d\n", 37, linearSearchSorted(&b, 37));
	printf("index of %d : %d\n", 32, binarySearch(&b, 32));

	return 0;
}
