#include <stdio.h>
#include <string.h>

#define SIZE 10

const char* list[] = {"i", "j", "k", "test", "test1", "sample", "samples", "data", "age", "length", "width", "sum", "average", "max", "min", "temp"};

int hash(char* c) {
	int len = strlen(c);
	int res = 0;
	for(int i = 0; i < len; i++) {
		res = (res * 10) + (c[i] - '0');
	}
	return res % SIZE;
}

int main(void) {
	int hashTable[SIZE];
	int size = sizeof(list) / sizeof(list[0]);
	for(int i = 0; i < size; i++) {
		hashTable[i] = hash(list[i]);
	}
	for(int i = 0; i < size; i++) {
		printf("* %s > %d\n", list[i], hashTable[i]);
	}
	return 0;
}
