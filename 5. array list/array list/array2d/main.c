#include <stdio.h>
#include "array2d.h"

int main(void) {
	int a[] = {1, 2, 3, 2, 3, 4, 1, 2, 2};
	int b[] = {2, 4, 3, 4, 3, 4, 1, 5, 2};

	Matrix *m1 = matrixNew(3, 3);
	matrixInit(m1, a);
	matrixPrint(m1);

	Matrix *m2 = matrixNew(3, 3);
	matrixInit(m2, b);
	matrixPrint(m2);

	Matrix *m3;
	m3 = matrixAdd(m1, m2);
	matrixPrint(m3);

	m3 = matrixMul(m1, m2);
	matrixPrint(m3);

	matrixFree(m1);
	matrixFree(m2);
	matrixFree(m3);

	return 0;
}
