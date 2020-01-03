#include "tree.h"

int main(void) {
	Tree t;
	init(&t, 100);

	for(int i = 1; i <=8; i++) {
		insert(&t, i);
	}

	printf("root : %3d\n", value(&t, 1));

	printf("current node(%3d), left(%3d), right(%3d)\n", 1, value(&t, leftChild(&t, 1)), value(&t, rightChild(&t, 1)));
	printf("current node(%3d), left(%3d), right(%3d)\n", 2, value(&t, leftChild(&t, 2)), value(&t, rightChild(&t, 2)));
	printf("current node(%3d), left(%3d), right(%3d)\n", 3, value(&t, leftChild(&t, 3)), value(&t, rightChild(&t, 3)));
	printf("current node(%3d), left(%3d), right(%3d)\n", 4, value(&t, leftChild(&t, 4)), value(&t, rightChild(&t, 4)));
	printf("parent of %d is %d\n", 5, value(&t, parent(&t, 5)));
}
