#ifndef _SEARCH_
#define _SEARCH_

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "stack.h"

typedef struct {
	int size;
	int* visited;
} Visited;

void initVisit(Visited*, int);
void DFS(Graph*, Visited*, int);
void BFS(Graph*, Visited*, int);

#endif
