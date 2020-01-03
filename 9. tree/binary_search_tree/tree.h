#ifndef _TREE_
#define _TREE_

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct _node {
	Element data;
	struct _node* left;
	struct _node* right;
} Node;

Node* createNode(Element);
void addChild(Node*, Node*);
void freeNode(Node*);

Node* findMax(Node*);
Node* findMin(Node*);
Node* findValue(Node*, Element);
void deleteNode(Node*, Element);

void preorder(Node*);
void print(Node*);
#endif
