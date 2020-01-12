#ifndef _QUEUE_
#define _QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

typedef int Element;

typedef struct {
	int front;
	int rear;
	int size;
	Element* data;
} Queue;

void initQueue(Queue*, int);
bool isEmptyQueue(const Queue*);
bool isFullQueue(const Queue*);
void enQueue(Queue*, Element);
Element deQueue(Queue*);

#endif
