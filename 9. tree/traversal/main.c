#include "tree.h"

int main(void) {
	Node* root = createNode(10);
	addLeftChild(root, createNode(20));
	addRightChild(root, createNode(30));

	Node* left = root->left;
	addLeftChild(left, createNode(40));
	addRightChild(left, createNode(50));

	printf("\n======== inorder =======\n");
	inorder(root);
	printf("\n");
	printf("\n======== preorder =======\n");
	preorder(root);
	printf("\n");
	printf("\n======== postorder =======\n");
	postorder(root);
	printf("\n");
}
