#ifndef _GRAPH_
#define _GRAPH_

#include <stdio.h>
#include <stdlib.h>

typedef enum { DIRECTED = 0, UNDIRECTED = 1 } type;

typedef struct {
	int** matrix;
	int type;
	int size;
} Graph;

void create(Graph*, int, int);
void insertEdge(Graph*, int, int);
void print(Graph*);
void graphVisit(Graph*);
void deleteEdge(Graph*, int, int);

#endif
