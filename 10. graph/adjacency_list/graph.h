#ifndef _GRAPH_
#define _GRAPH_

#include <stdio.h>
#include <stdlib.h>

typedef enum { DIRECTED = 0, UNDIRECTED = 1 } type;

typedef int Element;

typedef struct _node{
	Element data;
	struct _node* next;
}Node;

typedef struct {
	int size;
	Node* node;
	int type;
} Graph;

Node* createNode(int);
void create(Graph*, int, int);
void insertEdge(Graph*, int, int);
Node* findNode(Graph*, int);
void print(Graph*);
void deleteEdge(Graph*, int, int);

#endif
