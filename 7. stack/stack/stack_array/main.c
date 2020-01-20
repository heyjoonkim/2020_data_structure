#include "stack.h"

int main(void) {
	Stack s;
	int data[] = {1, 2, 3, 4, 5};

	init(&s);

	for(int i = 0; i < 5; i ++) {
		push(&s, data[i]);
		printf("Top : %d\n", top(&s));
	}

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	printf("%d\n", pop(&s));
	return 0;
}
