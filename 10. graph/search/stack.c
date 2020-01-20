#include "stack.h"

void initStack(Stack* s, int size) {
	s->data = (Element*)malloc(sizeof(Element) * size);
	s->size = size;
	s->top = -1;
}

bool isEmptyStack(const Stack* s) {
	return s->top == -1;
}

bool isFullStack(const Stack* s) {
	return s->top == (s->size -1);
}

Element topStack(const Stack* s) {
	if(isEmptyStack(s)) {
		printf("* stack is empty.\n");
		return -1;
	}
	return s->data[s->top];
}

Element popStack(Stack* s) {
	if(isEmptyStack(s)) {
		printf("* stack is empty.\n");
		return -1;
	}
	Element res = s->data[s->top];
	s->top--;
	return res;
}

void pushStack(Stack* s, const Element item) {
	if(isFullStack(s)) {
		printf("* stack is full.\n");
		return;
	} 
	s->top++;
	s->data[s->top] = item;
}
