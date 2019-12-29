#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int matrix[4][5] = {
		{0, 0, 3, 0, 4},
		{0, 0, 5, 7, 0}, 
		{0, 0, 0, 0, 0},
		{0, 2, 6, 0, 0},
	};
	int** res;
	int size = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 5; j++) {
			if(matrix[i][j] != 0) 
				size++;
		}
	}
	
	res = (int**)malloc(sizeof(int*) * size);
	for(int i = 0; i < size; i++) {
		res[i] = (int*)malloc(sizeof(int) * 3);
	}

	int index = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 5; j++) {
			if(matrix[i][j] != 0) {
				res[index][0] = i;
				res[index][1] = j;
				res[index][2] = matrix[i][j];
				index++;
			}
		}
	}

	printf("==== initial matrix ====\n");
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 5; j++) {
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}

	printf("==== sparse matrix ====\n");
	for(int i = 0; i < size; i++) {
		printf("%3d%3d%3d\n", res[i][0], res[i][1], res[i][2]);
	}
}

