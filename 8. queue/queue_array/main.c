#include "queue.h"

int main(void) {
	Queue q;
	init(&q, 5);

	enQueue(&q, 1);
	enQueue(&q, 2);
	printf("%3d\n", deQueue(&q));
	printf("%3d\n", deQueue(&q));

	enQueue(&q, 3);
	enQueue(&q, 4);
	printf("%3d\n", deQueue(&q));
	printf("%3d\n", deQueue(&q));

	enQueue(&q, 5);
	printf("%3d\n", deQueue(&q));

	printf("Queue size : %2d\n", q.size);

	enQueue(&q, 6);
	printf("%3d\n", deQueue(&q));

}
