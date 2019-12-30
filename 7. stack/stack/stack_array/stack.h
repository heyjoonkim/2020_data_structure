#ifndef _STACK_
#define _STACK_

#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef int Element;
typedef struct {
	Element stack[MAX];
	int top;
} Stack;

void init(Stack*);
bool isEmpty(const Stack*);
bool isFull(const Stack*);
void push(Stack*, Element);
Element pop(Stack*);
Element top(Stack*);

#endif
