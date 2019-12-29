#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "array.h"

void init(Array* a, int max) {
	if(max < 0) {
		printf("* error. Invalid array size %d.\n", max);
		return;
	}
	a->max = max;
	a->size = 0;
	a->data = (Element*)malloc(sizeof(Element) * max);
}

bool isEmpty(const Array* a) {
	return a->size == 0;
}

bool isFull(const Array* a) {
	return a->size == a->max;
}

void print(const Array* a) {
	printf("\n=== Print Array ===\n");
	for(int i = 0; i < a->size; i++) {
		printf("%3d", a->data[i]);
	}
	printf("\n");
}

bool isInList(const Array* a, Element item) {
	for(int i = 0; i < a->size; i++) {
		if(a->data[i] == item) {
			return true;
		}
	}
	return false;
}

void addAt(Array* a, Element item, int index) {
	if(isFull(a)) {
		printf("* error. Full array.\n");
		return;
	} else if(index > a->size) {
		printf("* error. Index out of range.\n");
		return;
	}
	for(int i = a->size; i >= index; i--) {
		a->data[i] = a->data[i-1];
	}
	a->data[index] = item;
	a->size++;
	printf("* Insert %d at %d. New array size : %d\n", item, index, a->size);
}

void append(Array* a, Element item) {
	addAt(a, item, a->size); 
}

void removeItem(Array* a, Element item) {
	if(isEmpty(a)) {
		printf("* error. Array is empty.\n");
		return;
	}
	int index = linearSearch(a, item);
	if(index == -1) {
		printf("* error. Item not in array.\n");
		return;
	}
	for(int i = index; i < a->size - 1; i++) {
		a->data[i] = a->data[i+1];
	}
	a->size--;
	printf("* Removed %d at index %d. New Array size : %d\n", item, index, a->size);
}

int linearSearch(const Array* a, Element item) {
	for(int i = 0; i < a->size; i++) {
		if(a->data[i] == item) {
			return i;
		}
	}
	return -1;
}

int linearSearchSorted(const Array* a, Element item) {
	for(int i = 0; i < a->size; i++) {
		if(a->data[i] == item) {
			return i;
		}
		else if(a->data[i] > item) {
			return -1;
		}
	}
	return -1;
}

void copyArray(Array* src, Array* dest) {
	printf("* copy array\n");
	dest->size = src->size;
	dest->max = src->max;
	dest->data = (Element*)malloc(sizeof(Element) * dest->max);
	for(int i = 0; i < dest->size; i++) {
		dest->data[i] = src->data[i];
	}
}

void selectionSort(Array* a) {
	printf("* selection sort\n");
	for(int i = 0; i < a->size-1; i++) {
		int min = a->data[i];
		int index = i;
		for(int j = i+1; j < a->size; j++) {
			if(min > a->data[j])  {
				min = a->data[j];
				index = j;
			}
		}
		swap(&a->data[i], &a->data[index]);
	}
}

void quickSort(Array* a, int start, int end) {
	if(start >= end) return;
	int key = a->data[start];
	int i = start + 1;
	int j = end;
	while(i <= j) {
		while(key > a->data[i] && i <= end) i++;
		while(key < a->data[j] && j >= start) j--;
		if(i >= j) swap(&a->data[j], &a->data[start]);
		else swap(&a->data[i], &a->data[j]);
	}
	quickSort(a, start, j-1);
	quickSort(a, j+1, end);
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int binarySearch(const Array* a, Element item) {
	int start = 0;
	int end = a->size - 1;
	int mid = (int)a->size / 2;
	while(true) {
		if(start >= end) {
			break;
		} else if(a->data[mid] == item) {
			return mid;
		} else if(a->data[mid] < item) {
			start = mid + 1;
			mid = (mid + end) / 2;
		} else {
			end = mid - 1;
			mid = (start + mid) / 2;
		}
	}
	return -1;
}

