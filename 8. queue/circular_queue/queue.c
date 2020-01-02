#include "queue.h"

void init(Queue* q, int size) {
	q->data = (Element*)malloc(sizeof(Element) * size);
	q->end = -1;
	q->front = -1;
	q->max = size;
	q->size = 0;
}

bool isFull(const Queue* q) {
	return q->size == q->max;
}

bool isEmpty(const Queue* q) {
	return q->size == 0;
}

void enQueue(Queue* q, Element item) {
	if(isFull(q)) {
		printf("* Error. Queue is full.\n");
		return;
	}
	q->end = (q->end + 1) % q->max;
	q->data[q->end] = item;
	q->size++;
}

Element deQueue(Queue* q) {
	if(isEmpty(q)) {
		printf("* Error. Queue is empty.\n");
		return -1;
	}
	q->front = (q->front + 1) % q->max;
	q->size--;
	return q->data[q->front];
}
