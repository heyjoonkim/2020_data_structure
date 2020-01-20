#include "graph.h"

int main(void) {
	Graph g;

	create(&g, 10, DIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 0, 4);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);

	print(&g);
	graphVisit(&g);

	deleteEdge(&g, 0, 1);
	graphVisit(&g);

	create(&g, 10, UNDIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);

	print(&g);
	graphVisit(&g);
}
