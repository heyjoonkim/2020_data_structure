#include <stdio.h>
#include "sparse.h"

int main(void) {
	int data1[4][5] = {
		{0, 0, 3, 0, 4},
		{0, 0, 5, 7, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 6, 0, 0},
	};
	int data2[4][5] = {
		{1, 0, 0, 0, 4},
		{0, 3, 0, 7, 0}, 
		{0, 0, 2, 2, 0},
		{0, 2, 0, 0, 0}
	};

	Sparse *s = create(4, 5, (int*)data1);
	print(s);
	printOriginal(s);

	printf("[%d][%d] value : %d\n", 0, 2, get(s, 0, 2));

	printf("=== after changing [0][2] = 10 ===\n");
	set(s, 0, 2, 10);
	print(s);
	printOriginal(s);

	printf("=== after inserting [2][1] = 20 ===\n");
	set(s, 2, 1, 20);
	print(s);
	printOriginal(s);

	return 0;
}
