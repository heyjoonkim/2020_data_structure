#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
	int data;
	struct _Node* prev;
	struct _Node* next;
} NODE;

typedef struct {
	int size;
	NODE* head;
	NODE* tail;
} LinkedList;

void init(LinkedList*);

void print(LinkedList*);

int getSize(LinkedList*);

NODE* createNode(int);

bool isEmpty(LinkedList*);

bool isInList(LinkedList*, int);

void addFirst(LinkedList*, int);

void addLast(LinkedList*, int);

void addPost(LinkedList*, int, int);

void removeItem(LinkedList*, int);

void disposeList(LinkedList*);

#endif
