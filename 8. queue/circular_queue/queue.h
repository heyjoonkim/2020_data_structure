#ifndef _QUEUE_
#define _QUEUE_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Element;
typedef struct{
	Element* data;
	int front;
	int end;
	int max;
	int size;
} Queue;

void init(Queue*, int);
bool isFull(const Queue*);
bool isEmpty(const Queue*);
void enQueue(Queue*, Element);
Element deQueue(Queue*);

#endif
