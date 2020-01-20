#include "search.h"

void initVisit(Visited* v, int size) {
	v->size = size;
	v->visited = (int*)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++) {
		v->visited[i] = 0;
	}
}

void DFS(Graph* g, Visited* v, int start) {
	v->visited[start] = 1;
	printf("%2d", start);
	Node* n = findNode(g, start);
	n = n->next;
	while(n != NULL) {
		if(v->visited[n->data] != 1) {
			DFS(g, v, n->data);
		}
		n = n->next;
	}
}

void BFS(Graph* g, Visited* v, int start) {
	Queue q;
	initQueue(&q, 10);

	enQueue(&q, start);
	v->visited[start] = 1;
	while(!isEmptyQueue(&q)) {
		Element e = deQueue(&q);
		printf("%2d", e);
		Node* n = findNode(g, e);
		n = n->next;
		while(n != NULL) {
			if(v->visited[n->data] != 1) {
				enQueue(&q, n->data);
				v->visited[n->data] = 1;
			}
			n = n->next;
		}
	}
}
