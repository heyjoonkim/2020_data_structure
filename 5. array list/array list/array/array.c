#include <stdio.h>
#include "array.h"

void print(const int* data) {
	for(int i = 0 ; i < MAX; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

int isInArray(const int* data, int target) {
	int res = -1;
	for(int i = 0; i < MAX; i++) {
		if(target == data[i])
			res = i;
	}
	return res;
}

int max(const int* data) {
	int max = data[0];
	for(int i = 1; i < MAX; i++ ) {
		if(max < data[i]) 
			max = data[i];
	}
	return max;
}
