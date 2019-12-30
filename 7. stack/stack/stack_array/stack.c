#include "stack.h"

void init(Stack* s) {
	s->top = -1;
}

bool isEmpty(const Stack* s) {
	return s->top == -1;
}

bool isFull(const Stack* s) {
	return s->top == (MAX - 1);
}

void push(Stack* s, Element item) {
	if(isFull(s)) {
		printf("* Error. Stack is full.\n");
		return;
	}
	s->top++;
	s->stack[s->top] = item;
}

Element pop(Stack* s) {
	if(isEmpty(s)) {
		printf("* Error. Stack is empty.\n");
		return -1;
	}
	Element res = s->stack[s->top];
	s->top--;
	return res;
}

Element top(Stack* s) {
	if(isEmpty(s)) {
		printf("* Error. Stack is empty.\n");
		return -1;
	}
	Element res = s->stack[s->top];
	return res;
}
