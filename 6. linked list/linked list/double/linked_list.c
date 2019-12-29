#include "linked_list.h"

void init(LinkedList* l) {
	l->size = 0;
	l->head = NULL;
	l->tail = NULL;
}

void print(LinkedList* l) {
	printf("\n==== print list ====\n");
	if(isEmpty(l)) {
		printf("* Empty list.\n");
	} else {
		NODE* c = l->head;
		while(c != NULL) {
			printf("%3d", c->data);
			c = c->next;
		}
		printf("\n");
	}
}

int getSize(LinkedList* l) {
	return l->size;
}

NODE* createNode(int data) {
	NODE* res = (NODE*)malloc(sizeof(NODE));
	res->data = data;
	res->next = NULL;
	res->prev = NULL;
	return res;
}

bool isEmpty(LinkedList* l) {
	return getSize(l) == 0;
}

bool isInList(LinkedList* l, int data) {
	if(isEmpty(l)) {
		printf("* Empty list.\n");
	} else {
		NODE* n = l->head;
		while(n != NULL) {
			if(n->data == data) {
				return true;
			}
			n = n->next;
		}
	}
	return false;
}

void addPost(LinkedList* l, int index, int data) {
	if(index < 1 || index > l->size + 1) {
		printf("* Error. Index out of range.\n");
		return;
	}
	NODE* n = createNode(data);
	if(isEmpty(l)) {
		l->head = n;
		l->tail = n;
	} else if(index == 1) {
		n->next = l->head;
		l->head->prev = n;
		l->head = n;
	} else if(index == l->size + 1) {
		n->prev = l->tail;
		l->tail->next = n;
		l->tail = n;
	} else {
		NODE* c = l->head;
		int i = 1;
		while(c != NULL) {
			if(i == index) {
				c->prev->next = n;
				n->prev = c->prev;
				n->next = c;
				c->prev = n;
				break;
			}
			c = c->next;
			i++;
		}
	}
	l->size++;
}

void addFirst(LinkedList* l, int data) {
	addPost(l, 1, data);
}

void addLast(LinkedList* l, int data) {
	addPost(l, l->size + 1, data);
}

void removeItem(LinkedList* l, int data) {
	if(isEmpty(l)) {
		printf("* Empty list.\n");
		return;
	}
	NODE* c = l->head;
	while(c != NULL) {
		if(c->data == data) {
			if(c == l->head) {
				l->head = l->head->next;
			} else if(c == l->tail) {
				l->tail = l->tail->prev;
				free(l->tail->next);
				l->tail->next = NULL;
			} else {
				c->prev->next = c->next;
				c->next->prev = c->prev;
				free(c);
			}
			break;
		}
		c = c->next;
	}
	l->size--;
}
			










