#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <stdbool.h>

typedef int Element;

typedef struct {
	int max;
	int size;
	Element* data;
} Array;

void init(Array* a, int max);
bool isEmpty(const Array* a);
bool isFull(const Array* a);
void print(const Array* a);
bool isInList(const Array* a, Element item);
void append(Array* a, Element item);
void addAt(Array* a, Element item, int index);
void removeItem(Array* a, Element item);

int linearSearch(const Array* a, Element item);
int linearSearchSorted(const Array* a, Element item);

int binarySearch(const Array* a, Element item);

void copyArray(Array* src, Array* dest);

void selectionSort(Array* a);
void quickSort(Array* a, int start, int end);

void swap(Element* a, Element* b);
#endif
