#include "hashing.h"

int hash(const HashTable* t, char* key) {
	int res = 0;
	int len = strlen(key);
	int size = t->max;
	for(int i = 0; i < len; i++) {
		res = (res * 10) + (key[i] - '0');
	}
	return res % size;
}

void init(HashTable* t, int size) {
	t->max = size;
	t->size = 0;
	t->table = (Node**)malloc(sizeof(Node*) * size);
	for(int i = 0; i < size; i++) {
		t->table[i] = NULL;
	}
}

Node* createNode(char* key, int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = (char*)malloc(sizeof(strlen(key)+1));
	strcpy(node->key, key);
	node->value = value;
	node->next = NULL;
	return node;
}

void updateValue(Node* node, int value) {
	node->value = value;
}

void insert(HashTable* t, char* key, int value) {
	int index = hash(t, key);
	Node* node = findNode(t, index, key);
	if(t->table[index] == NULL) {
		t->table[index] = createNode(key, value);
	} else if(node == NULL) {
		node = t->table[index];
		while(node->next != NULL) {
			node = node->next;
		}
		node->next = createNode(key, value);
	} else {
		updateValue(node, value);
	}
}

Node* findNode(HashTable* t, int index, char* key) {
	Node* node = t->table[index];
	while(node != NULL) {
		if(strcmp(node->key, key) == 0){ 
			return node;
		} 
		node = node->next;
	}
	return node;
}

void print(const HashTable* t) {
	printf("* print hash table.\n");
	int size = t->max;
	for(int i = 0; i < size; i++) {
		printf("(index : %3d)", i);
		Node* node = t->table[i];
		while(node != NULL) {
			printf(" -> (key:%10s, value:%3d)", node->key, node->value);
			node = node->next;
		}
		printf("\n");
	}
}
