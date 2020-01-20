#include "queue.h"

void initQueue(Queue* q, int size) {
	q->front = 0;
	q->rear = 0;
	q->size = size;
	q->data = (Element*)malloc(sizeof(Element) * size);
}

bool isEmptyQueue(const Queue* q) {
	return q->front == q->rear;
}

bool isFullQueue(const Queue* q) {
	return (q->rear - q->front) == (q->size - 1);
}

void enQueue(Queue* q, Element item) {
	if(isFullQueue(q)) {
		printf("* queue is full.\n");
		return;
	}
	q->data[q->rear] = item;
	q->rear = (q->rear + 1) % q->size;
}

Element deQueue(Queue* q) {
	if(isEmptyQueue(q)) {
		printf("* queue is empty.\n");
		return -1;
	}
	Element res = q->data[q->front];
	q->front = (q->front + 1) % q->size;
	return res;
}
