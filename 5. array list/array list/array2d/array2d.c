#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array2d.h"

Matrix* matrixNew(const int row, const int col) {
	Matrix* res = (Matrix*)malloc(sizeof(Matrix));
	res->col = col;
	res->row = row;

	res->val = (item**)malloc(sizeof(item*) * row);
	for(int i = 0; i < row; i++) {
		res->val[i] = (item*)malloc(sizeof(item) * col);
		memset(res->val[i], 0, sizeof(item) * col);
	}
	return res;
}

void matrixInit(Matrix* m, const int* arr) {
	for(int i = 0; i < m->row; i++) {
		for(int j = 0; j < m->col; j++) {
			m->val[i][j] = arr[i * m->col + j];
		}
	}
}

void matrixPrint(const Matrix* m) {
	printf("==== print matrix ====\n");
	for(int i = 0; i < m->row; i++) {
		for(int j = 0; j < m->col; j++) {
			printf("%4d", m->val[i][j]);
		}
		printf("\n");
	}
}

void matrixFree(Matrix* m) {
	for(int i = 0; i < m->row; i++)  {
		free(m->val[i]);
	}
	free(m->val);
	free(m);
}

Matrix* matrixAdd(const Matrix* m1, const Matrix* m2) {
	if(m1->row != m2->row || m1->col != m2->col) {
		printf("* error. unable to add matrix.\n");
		return NULL;
	}

	Matrix* res;
	int row = m1->row;
	int col = m1->col;
	res = matrixNew(row, col);

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			res->val[i][j] = m1->val[i][j] + m2->val[i][j];
		}
	}
	return res;
}

Matrix* matrixMul(const Matrix* m1, const Matrix* m2) {
	if(m1->row != m2->col) {
		printf("* error. unable to multiply matrix.\n");
		return NULL;
	}
	Matrix* res;
	int row = m1->row;
	int col = m2->col;
	int iter = m1->col;
	res = matrixNew(row, col);
	
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			for(int k = 0; k < iter; k++) {
				res->val[j][i] += m1->val[j][k] * m2->val[k][i];
			}
		}
	}

	return res;
}
	

	
