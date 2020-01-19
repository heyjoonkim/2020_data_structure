#ifndef _HASHING_
#define _HASHING_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
	char* key;
	int value;
	struct _Node* next;
} Node;

typedef struct {
	int max;
	int size;
	Node** table;
} HashTable;

int hash(const HashTable*, char*);
void init(HashTable*, int);
void updateValue(Node*, int);
Node* createNode(char*, int);
void insert(HashTable*, char*, int);
Node* findNode(HashTable*, int, char*);
void print(const HashTable*);

#endif
