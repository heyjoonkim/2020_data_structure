#include "graph.h"

int main(void) {
	Graph g;
	printf("* udirected graph.\n");
	create(&g, 5, UNDIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 0, 4);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);
	insertEdge(&g, 3, 4);

	print(&g);

	printf("* directed graph.\n");
	create(&g, 5, DIRECTED);

	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 0, 4);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);
	insertEdge(&g, 3, 4);

	print(&g);
}
	
