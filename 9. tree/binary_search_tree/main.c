#include "tree.h"

int main(void) {
	Node* root = createNode(31);
	addChild(root, createNode(16));
	addChild(root, createNode(45));
	print(root);

	addChild(root, createNode(24));
	addChild(root, createNode(7));
	print(root);

	addChild(root, createNode(19));
	addChild(root, createNode(29));
	print(root);
		
	deleteNode(root, 7);
	print(root);

	deleteNode(root, 16);
	print(root);

	deleteNode(root, 24);
	print(root);

	deleteNode(root, 31);
	print(root);
}
