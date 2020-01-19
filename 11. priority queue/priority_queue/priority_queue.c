#include "priority_queue.h"

void init(Heap* h, int size) {
	h->size = 0;
	h->max = size;
	h->data = (Element*)malloc(sizeof(Element) * size);
}

bool isEmpty(Heap* h) {
	return h->size == 0;
}

bool isFull(Heap* h) {
	return h->size == h->max;
}

void swap(Element* a, Element* b) {
	Element tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(const Heap* h) {
	for(int i = 0; i < h->size; i++) {
		printf("%2d", h->data[i]);
	}
	printf("\n");
}

int parent(int index) {
	if(index == 0) 
		return 0;
	else 
		return (index - 1) / 2;
}

int leftChild(Heap* h, int index) {
	int res =  2 * index + 1;
	if(res > h->size - 1)
		return index;
	else 
		return res;
}

int rightChild(Heap* h, int index) {
	int res = 2 * index + 2;
	if(res > h->size - 1)
		return index;
	else 
		return res;
}

void add(Heap* h, Element item) {
	if(isFull(h)) {
		printf("* Heap is full.\n");
		return ;
	}
	int index = h->size;
	h->data[index] = item;
	h->size++;
	while(index < h->size) {
		int parent_index = parent(index);
		Element parent = h->data[parent_index];
		if(parent < item) {
			swap(&h->data[parent_index], &h->data[index]);
			index = parent_index;
		} else {
			break;
		}
	}
}

Element removeItem(Heap* h) {
	if(isEmpty(h)) {
		printf("* Heap is empty.\n");
		return -1;
	}
	Element res = h->data[0];
	h->size--;
	int index = h->size;
	swap(&h->data[0], &h->data[index]);
	Element item = h->data[0];
	index = 0;
	while(index < h->size) {
		int left = leftChild(h, index);
		int right = rightChild(h, index);

		if(item >= h->data[left] && item >= h->data[right])
			break;
		else {
			if(h->data[left] > h->data[right]) {
				swap(&h->data[index], &h->data[left]);
				index = left;
			} else {
				swap(&h->data[index], &h->data[right]);
				index = right;
			}
		}
	}
	return res;
}
