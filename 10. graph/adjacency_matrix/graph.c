#include "graph.h"

void create(Graph* g, int size, int type) {
	g->matrix = (int**)malloc(sizeof(int*) * size);
	for(int i = 0; i < size; i++) {
		g->matrix[i] = (int*)malloc(sizeof(int) * size);
	}

	g->type = type;
	g->size = size;
}


void insertEdge(Graph* g, int from, int to) {
	if(g->type == DIRECTED) {
		g->matrix[from][to] = 1;
	} else {
		g->matrix[from][to] = 1;
		g->matrix[to][from] = 1;
	}
}

void deleteEdge(Graph* g, int from, int to) {
	if(g->type == DIRECTED) {
		g->matrix[from][to] = 0;
	} else {
		g->matrix[from][to] = 0;
		g->matrix[from][to] = 0;
	}
}

void print(Graph* g) {
	int size = g->size;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("%3d", g->matrix[i][j]);
		}
		printf("\n");
	}
}

void graphVisit(Graph* g) {
	char* pointer;
	int size = g->size;
	if(g->type == DIRECTED) {
		pointer = "->";
		printf("digraph G {\n");
	} else {
		pointer = "--";
		printf("graph G{\n");
	}
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(g->matrix[i][j] == 1) {
				printf("\t%2d %s%2d\n", i, pointer, j);
			}
		}
	}
	printf("}\n");
}
