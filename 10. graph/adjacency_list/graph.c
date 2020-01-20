#include "graph.h"

Node* createNode(int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

void create(Graph* g, int size, int type) {
	g->node = (Node*)malloc(sizeof(Node) * size);
	g->size = size;
	g->type = type;
	for(int i = 0; i < size; i++) {
		g->node[i].data = i;
		g->node[i].next = NULL;
	}
}

void insertEdge(Graph* g, int from, int to) {
	Node* f = findNode(g, from);
	Node* t = createNode(to);
	if(f != NULL) {
		t->next = f->next;
		f->next = t;
	}
	if(g->type == UNDIRECTED) {
		f = findNode(g, to);
		t = createNode(from);
		if(f != NULL) {
			t->next = f->next;
			f->next = t;
		}
	}
}

Node* findNode(Graph* g, int target) {
	if(g->size < target) {
		printf("* error. index out of range.\n");
		return NULL;
	}
	return &g->node[target];
}

void print(Graph* g) {
	int size = g->size;
	Node* n;
	char* pointer;
	
	if(g->type == DIRECTED) pointer = "->";
	else pointer = "--";

	for(int i = 0; i < size; i++) {
		n = findNode(g, i);
		printf("Vertex %2d:", i);
		n = n->next;
		while(n != NULL) {
			printf(" %s%2d", pointer, n->data);
			n = n->next;
		}
		printf("\n");
	}
}

void deleteEdge(Graph* g, int from, int to) {
	Node* n = findNode(g, from);
	Node* p = n->next;
	Node* prev = n;
	while(p != NULL) {
		if(p->data == to) {
			prev->next = p->next;
			free(p);
		}
		prev = p;
		p = p->next;
	}
}

