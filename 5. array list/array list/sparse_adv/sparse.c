#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"

Sparse* create(int row, int col, int* data) {
	Sparse* s = (Sparse*)malloc(sizeof(Sparse));
	s->rowCount = row;
	s->colCount = col;
	int size = 0;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(data[i * col + j] != 0) {
				size++;
			}
		}
	}
	s->valCount = size;
	s->data = (Element*)malloc(sizeof(Element) * size);
	
	int index = 0;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(data[i * col + j] != 0) {
				s->data[index].row = i;
				s->data[index].col = j;
				s->data[index].val = data[i*col + j];
				index++;
			}
		}
	}
	return s;
}

void print(const Sparse* s) {
	printf("=== print sparse matrix === \n");
	for(int i = 0; i < s->valCount; i++) {
		printf("%3d%3d%3d\n", s->data[i].row, s->data[i].col, s->data[i].val);
	}
}

void printOriginal(const Sparse* s) {
	printf("=== print original matrix === \n");
	int row = s->rowCount;
	int col = s->colCount;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			int found = 0;
			for(int k = 0 ; k < s->valCount; k++) {
				if(s->data[k].row == i && s->data[k].col == j) {
					printf("%3d", s->data[k].val);
					found = 1;
					break;
				}
			}
			if(found == 0)
				printf("%3d", 0);
		}
		printf("\n");
	}
}

void set(Sparse* s, int row, int col, int val) {
	int found = 0;
	for(int i = 0; i < s->valCount; i++) {
		if(s->data[i].row == row && s->data[i].col == col) {
			printf("=== change data ===\n");
			s->data[i].val = val;
			found = 1;
		}
	}
	if(found == 0)
		printf("* unable to find value.\n");
}

int get(const Sparse*s, int row, int col) {
	for(int i = 0; i < s->valCount; i++) {
		if(s->data[i].row == row && s->data[i].col == col) 
			return s->data[i].val;
	}
	printf("* value not found.\n");
	return -1;
}			
