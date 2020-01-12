#ifndef _GRAPH_
#define _GRAPH_

#include <stdio.h>
#include <stdlib.h>

typedef enum{ DIRECTED = 0, UNDIRECTED = 1} type;

typedef int Element;

typedef struct _node {
	Element data;
	struct _node* next;
} Node;

typedef struct {
	Node* data;
	int size;
	int type;
} Graph;

void initGraph(Graph*, int, int);
void insertEdge(Graph*, int, int);
Node* findNode(Graph*, int);
Node* createNode(Element);
void printGraph(Graph*);


#endif
