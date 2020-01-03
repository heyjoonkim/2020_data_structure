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
void addLeftChild(Node*, Node*);
void addRightChild(Node*, Node*);

void freeNode(Node*);

void preorder(Node*);
void inorder(Node*);
void postorder(Node*);

#endif
