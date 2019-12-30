#ifndef _POSTFIX_
#define _POSTFIX_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PLUS '+'
#define MINUS '-'
#define DIV '/'
#define MUL '*'
#define BLANK ' '
#define OPEN '('
#define CLOSE ')'

typedef char Element;
typedef struct {
	char* stack;
	int top;
	int max;
} Stack;

void init(Stack*, char*);
bool isFull(const Stack*);
bool isEmpty(const Stack*);
void push(Stack*, Element item);
Element pop(Stack*);
Element top(Stack*);
char* toPostfix(Stack*, char*);
int calPostfix(Stack*, char*);
bool isOperand(char c);
int weight(char c);
char operation(char, char, char);
int calPostfix(Stack*, char*);

#endif
