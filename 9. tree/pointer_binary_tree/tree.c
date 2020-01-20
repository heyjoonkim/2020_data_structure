#include "tree.h"

Node* init(Element e) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = e;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void addLeftChild(Node* parent, Node* child) {
	parent->left = child;
}

void addRightChild(Node* parent, Node* child) {
	parent->right = child;
}

void inorder(Node* node) {
	if(node != NULL) {
		inorder(node->left);
		printf("%3d", node->data);
		inorder(node->right);
	}
}

void freeNodes(Node* node) {
	if(node != NULL) {
		freeNodes(node->left);
		freeNodes(node->right);
		free(node);
	}
}
