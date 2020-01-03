#include "tree.h"

int main(void) {
	Node* root = init(1);
	root->left = init(2);
	root->right = init(3);

	Node* left = root->left;
	left->left = init(4);
	left->right = init(5);

	Node* right = root->right;
	right->left = init(6);
	right->right = init(7);

	printf("* print in inorder.\n");
	inorder(root);
	printf("\n");
	
	freeNodes(root);
}
