#ifndef _STACK_
#define _STACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char Element;
typedef struct {
	char* stack;
	int top;
	int max;
} Stack;

void init(Stack*, char*);
bool isEmpty(const Stack*);
bool isFull(const Stack*);
void push(Stack*, Element);
Element pop(Stack*);
Element top(Stack*);
void check(char* string);

#endif
