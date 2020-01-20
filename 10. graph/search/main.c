#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "search.h"

#define SIZE 6

int main(void) {
	Graph g;

	initGraph(&g, SIZE, DIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 4);
	insertEdge(&g, 3, 4);
	insertEdge(&g, 4, 5);

	printGraph(&g);

	Visited v;
	initVisit(&v, SIZE);
	printf("* Depth First Search (DFS) :\n");
	DFS(&g, &v, 0);
	printf("\n");
	printf("* Beadth First Search (BFS) : \n");
	initVisit(&v, SIZE);
	BFS(&g, &v, 0);
	printf("\n");
}


