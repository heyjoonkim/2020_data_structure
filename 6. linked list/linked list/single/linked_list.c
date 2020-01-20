#include "linked_list.h"

void init(LinkedList* l) {
	l->size = 0;
	l->head = NULL;
}

void print(LinkedList* l) {
	printf("\n==== print list ====\n");
	if(isEmpty(l)) {
		printf("* empty list.\n");
		return;
	}
	int size = l->size;
	int index = 0;
	printf("index : ");
	for(int i = 1; i <= size; i++) {
		printf("%3d", i);
	}
	printf("\n");
	printf("data  : ");
	if(!isEmpty(l)) {
		NODE* n = l->head;
		while(n != NULL) {
			printf("%3d", n->data);
			n = n->next;
		}
	}
	printf("\n");
}

int getSize(LinkedList* l) {
	return l->size;
}

NODE* createNode(int data) {
	NODE* res = (NODE*)malloc(sizeof(NODE));
	res->data = data;
	res->next = NULL;
	return res;
}

bool isEmpty(LinkedList* l) {
	return getSize(l) == 0;
}

bool isInList(LinkedList* l, int data) {
	NODE* n = l->head;
	while(n != NULL) {
		if(n->data == data) {
			return true;
		}
		n = n->next;
	}
	return false;
}

void addFirst(LinkedList* l, int data) {
	addPost(l, 1, data);
}

void addLast(LinkedList* l, int data) {
	addPost(l, l->size, data);
}

void addPost(LinkedList* l, int index, int data) {
	NODE* n = createNode(data);
	int i = 0;
	if(index < 1 || index > l->size + 1) {
		printf("* Error. Index out of range.\n");
		return;
	}
	
	if(index == 1) {
		n->next = l->head;
		l->head = n;
	} else {
		NODE* c = l->head;
		while(c != NULL) {
			i++;
			if(i == index - 1)
				break;
			c = c->next;
		}
		n->next = c->next;
		c->next = n;
	}
	l->size++;
}

void removeItem(LinkedList* l, int data) {
	if(isEmpty(l)) {
		printf("* Empty list.\n");
	} else {
		if(!isInList(l, data)) {
			printf("* Error. Data doesn't exist.\n");
			return;
		}
		NODE* c = l->head;
		NODE* before = l->head;
		while(c != NULL) {
			if(c->data == data) {
				if(l->head == c) {
					l->head = l->head->next;
				} else {
					before->next = c->next;
					free(c);
				}
			}
			before = c;
			c = c->next;
		}
	}
}





