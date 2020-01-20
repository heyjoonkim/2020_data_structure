#include <stdio.h>
#include "array.h"

int main(void) {
	int data[10] = {23, 42, 52, 12, 5, 19, 100, 33, 54, 2};

	print(data);

	printf("%d\n", isInArray(data, 12));
	printf("%d\n", isInArray(data, 11));
	printf("max = %d\n", max(data));

}
