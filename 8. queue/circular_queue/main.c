#include "queue.h"

int main(void) {
	Queue q;
	init(&q, 5);

	int i = 0;
	while(!isFull(&q)) {
		enQueue(&q, i);
		i++;
	}
	printf("size : %3d\n", q.size);
	printf("front : %3d, end : %3d, max : %3d\n", q.front, q.end, q.max);
	printf("full(%d), empty(%d)\n", isFull(&q), isEmpty(&q));

	Element e;
	while(!isEmpty(&q)) {
		e = deQueue(&q);
		printf("%3d\n", e);
	}

	printf("===========\n");
	printf("size : %3d\n", q.size);
	printf("front : %3d, end : %3d, max : %3d\n", q.front, q.end, q.max);
	printf("full(%d), empty(%d)\n", isFull(&q), isEmpty(&q));

	while(!isFull(&q)) {
		enQueue(&q, i);
		i++;
	}
	printf("===========\n");
	printf("size : %3d\n", q.size);
	printf("front : %3d, end : %3d, max : %3d\n", q.front, q.end, q.max);
	printf("full(%d), empty(%d)\n", isFull(&q), isEmpty(&q));

	while(!isEmpty(&q)) {
		e = deQueue(&q);
		printf("%3d\n", e);
	}

	
	printf("===========\n");
	printf("size : %3d\n", q.size);
	printf("front : %3d, end : %3d, max : %3d\n", q.front, q.end, q.max);
	printf("full(%d), empty(%d)\n", isFull(&q), isEmpty(&q));
}
