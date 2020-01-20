#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct {
	int size;
	int max;
	Element *data;
} Heap;

void init(Heap*, int);
bool isEmpty(Heap*);
bool isFull(Heap*);
Element removeItem(Heap*);
void add(Heap*, Element);
void print(const Heap*);
int parent(int);
int leftChild(Heap*, int);
int rightChild(Heap*, int);
void swap(Element*, Element*);

#endif

