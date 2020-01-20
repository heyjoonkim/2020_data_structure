#include "graph.h"

void initGraph(Graph* g, int size, int type) {
	g->size = size;
	g->type = type;
	g->data = (Node*)malloc(sizeof(Node) * size);
	for(int i = 0; i < size; i++) {
		g->data[i].data = i;
		g->data[i].next = NULL;
	}
}

Node* findNode(Graph* g, int index) {
	return &g->data[index];
}

Node* createNode(Element data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

void insertEdge(Graph* g, int from, int to) {
	Node* f = findNode(g, from);
	Node* t = createNode(to);
	t->next = f->next;
	f->next = t;
	if(g->type == UNDIRECTED) {
		f = findNode(g, to);
		t = createNode(from);
		t->next = f->next;
		f->next = t;
	}
}

void printGraph(Graph* g) {
	char* pointer;
	Node* n;
	if(g->type == DIRECTED) pointer = "->";
	else pointer = "--";

	for(int i = 0; i < g->size; i++) {
		printf("Vertex %2d :", i);
		n = findNode(g, i);
		n = n->next;
		while(n != NULL) {
			printf("%s%2d", pointer, n->data);
			n = n->next;
		}
		printf("\n");
	}
}

