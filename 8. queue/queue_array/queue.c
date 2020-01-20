#include "queue.h"

void init(Queue* q, int size) {
	q->data = (Element*)malloc(sizeof(Element) * size);
	q->max = size;
	q->front = -1;
	q->end = -1;
	q->size = 0;
}

bool isFull(const Queue* q) {
	return q->front == (q->max - 1);
}

bool isEmpty(const Queue* q) {
	return q->front == q->end;
}

void enQueue(Queue* q, Element item) {
	if(isFull(q)) {
		printf("* Error. Queue is full.\n");
		return;
	}
	q->end++;
	q->data[q->end] = item;
	q->size++;
}

Element deQueue(Queue* q) {
	if(isEmpty(q)) {
		printf("* Error. Queue is empty.\n");
		exit(0);
	}
	q->front++;
	q->size--;
	return q->data[q->front];
}
