#include "postfix.h"

void init(Stack* s, char* string) {
	int len = strlen(string);
	s->stack = (char*)malloc(sizeof(char) * len);
	s->max = len - 1;
	s->top = -1;
}

bool isFull(const Stack* s) {
	return s->top == s->max;
}

bool isEmpty(const Stack* s) {
	return s->top == -1;
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

bool isOperand(char c) {
	if(c == PLUS || c == MINUS || c == DIV || c == MUL) 
		return true;
	else
		return false;
}

bool isParen(char c) {
	if(c == OPEN || c == CLOSE)
		return true;
	else 
		return false;
}

int weight(char c) {
	if(c == PLUS || c == MINUS)
		return 1;
	else if(c == DIV || c == MUL)
		return 2;
	else
		return -1;
}

char* toPostfix(Stack* s, char* string) {
	int len = strlen(string);
	int index = 0;
	char* res = (char*)malloc(sizeof(char) * (len + 1));
	for(int i = 0; i < len; i++) {
		char l = string[i];
		if(l == BLANK) continue;
		else if(isOperand(l)) {
			if(isEmpty(s)) {
				push(s, l);
			} else {
				int w = weight(l);
				char t = top(s);
				int top_w = weight(t);
				if(w <= top_w) {
					pop(s);
					res[index] = t;
					index++;
					push(s, l);
				} else {
					push(s, l);
				}
			}
		} else if(isParen(l)) {
			if(l == OPEN) {
				push(s, l);
			} else if(l == CLOSE) {
				char c;
				while(true) {
					c = pop(s);
					if(c == OPEN) break;
					else {
						res[index] = c;
						index++;
					}
				}
			}
		} else {
			res[index] = l;
			index++;
		}
	}
	while(!isEmpty(s)) {
		char c = pop(s);
		res[index] = c;
		index++;
	}

	return res;
}

int calPostfix(Stack* s, char* exp) {
	int len = strlen(exp);
	char c;
	char op1, op2;
	char res;
	for(int i = 0; i < len; i++) {
		c = exp[i];
		if(isOperand(c)) {
			op1 = pop(s);
			op2 = pop(s);
			res = operation(c, op1, op2);
			push(s, res);
		} else {
			push(s, c);
		}
	}
	res = pop(s);
	return (int)res - '0';
}

char operation(char op, char a, char b) {
	char op1 = a - '0';
	char op2 = b - '0';
	char res;
	if(op == PLUS) {
		res = op1 + op2;
	} else if(op == MINUS) {
		res = op1 - op2;
	} else if(op == DIV) {
		res = op1 / op2;
	} else if(op == MUL) {
		res = op1 * op2;
	}
	return res + '0';
}
