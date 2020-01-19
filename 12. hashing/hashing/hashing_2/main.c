#include "hashing.h"

char* key[] = { "i", "j", "k", "test", "test1", "sample", "samples", "data", "age", "length", "width", "sum", "average", "max", "min", "temp"};

int value[] = {0, 1, 2, 10, 20, 30, 31, 100, 48, 170, 70, 100, 50, 1000, 0, 44};

int main(void) {
	int size = sizeof(key) / sizeof(key[0]);
	HashTable t;
	init(&t, 10);

	for(int i = 0; i < size; i++) {
		insert(&t, key[i], value[i]);
	}
	print(&t);

	insert(&t, "i", 111);
	insert(&t, "samples", 222);
	print(&t);

	for(int i = 0; i < size; i++) {
		int index = hash(&t, key[i]);
		Node* node = findNode(&t, index, key[i]);
		if(node != NULL) {
			printf("found node : (%s:%3d)\n", node->key, node->value);
		}
	}

}
