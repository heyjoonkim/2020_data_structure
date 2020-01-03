#ifndef _TREE_
#define _TREE_

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct {
	Element* data;
	int size;
	int max;
} Tree;

void init(Tree*, int);
int leftChild(const Tree*, const int);
int rightChild(const Tree*, const int);
int parent(const Tree*, const int);
Element value(const Tree*, const int);
void insert(Tree*, const Element);

#endif
