#include "stack.h"

void init(Stack* s, char* string) {
	// if string = "abc", len = 3;
	int len = strlen(string);
	s->stack = (char*)malloc(sizeof(char) * len);
	s->top = -1;
	s->max = len;
}

bool isEmpty(const Stack* s) {
	return s->top == -1;
}

bool isFull(const Stack* s) {
	return s->top == (s->max - 1);
}

void push(Stack* s, Element item) {
	if(isFull(s)) {
		printf("* Error. Stack is Full\n");
		return;
	}
	s->top++;
	s->stack[s->top] = item;
}

Element pop(Stack* s) {
	if(isEmpty(s)) {
		printf("* Error. Stack is empty\n");
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

void check(char* string) {
	printf("* Checking parenthesis match for string \"%s\".\n", string);
	Stack s;
	init(&s, string);
	char open1 = '(';
	char close1 = ')';
	char open2 = '{';
	char close2 = '}';
	int len = strlen(string);
	for(int i = 0; i < len; i++) {
		if(string[i] == open1 || string[i] == open2) {
			push(&s, string[i]);
		} else if(string[i] == close1 || string[i] == close2) {
			Element t = top(&s);
			if(t == open1 && string[i] == close1) {
				pop(&s);
			} else if(t == open2 && string[i] == close2) {
				pop(&s);
			} else {
				printf("* Error. Incorrect string.\n");
				return;
			}
		}
	}
	if(isEmpty(&s)) {
		printf("* Correct string.\n");
	} else {
		printf("* Error. Incorrect string.\n");
	}
}
