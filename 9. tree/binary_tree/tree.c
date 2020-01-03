#include "tree.h"

void init(Tree* t, int size) {
	t->data = (Element*)malloc(sizeof(Element) * size);
	t->size = 0;
	t->max = size;
}

int leftChild(const Tree* t, const int index) {
	if(t->size < index * 2) {
		printf("* Error. No left child.\n");
		return -1;
	}
	return index * 2;
}

int rightChild(const Tree* t, const int index) {
	if(t->size < index * 2 + 1) {
		printf("* Error. No right child.\n");
		return -1;
	}
	return 2 * index + 1;
}

int parent(const Tree* t, const int index) {
	if(index == 1) return 0;
	return index / 2;
}

Element value(const Tree* t, const int index) {
	if(index < 0) {
		printf("* Error. No element.\n");
		return -1;
	} else if(index >= t->max) {
		printf("* Error. Index out of range.\n");
		return -1;
	}
	return t->data[index];
}

void insert(Tree* t, const Element e) {
	if(t->size >= t->max + 1) {
		printf("* Error. Tree is full.\n");
		return;
	}
	t->size++;
	t->data[t->size] = e;
}
