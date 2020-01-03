#ifndef _TREE_
#define _TREE_

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct _Node {
	Element data;
	struct _Node* left;
	struct _Node* right;
} Node;

Node* init(Element);
void addLeftChild(Node*, Node*);
void addRightChild(Node*, Node*);

void inorder(Node*);

void freeNodes(Node*);

#endif
