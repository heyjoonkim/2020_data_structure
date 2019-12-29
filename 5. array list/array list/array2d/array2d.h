#ifndef ARRAY_2D
#define ARRAY_2D

typedef int item;
typedef struct _m {
	int col;
	int row;
	item** val;
} Matrix;

Matrix* matrixNew(const int, const int);
void matrixInit(Matrix*, const int*);
void matrixPrint(const Matrix*);
Matrix* matrixAdd(const Matrix*, const Matrix*);
Matrix* matrixMul(const Matrix*, const Matrix*);
void matrixFree(Matrix*);

#endif
