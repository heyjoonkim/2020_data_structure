#ifndef _STACK_
#define _STACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;
typedef struct {
	Element* data;
	int size;
	int top;
} Stack;

void initStack(Stack*, int);
bool isEmptyStack(const Stack*);
bool isFullStack(const Stack*);
Element topStack(const Stack*);
Element popStack(Stack*);
void pushStack(Stack*, const Element);

#endif
