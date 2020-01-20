#include "tree.h"

Node* createNode(Element e) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = e;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void addLeftChild(Node* parent, Node* child) {
	if(parent->left != NULL) {
		printf("* Error. Left child already exists.\n");
		return;
	}
	parent->left = child;
}

void addRightChild(Node* parent, Node* child) {
	if(parent->right != NULL) {
		printf("* Error. Right child already exists.\n");
		return;
	}
	parent->right = child;
}

void freeNode(Node* n) {
	if(n != NULL) {
		freeNode(n->left);
		freeNode(n->right);
		free(n);
	}
}

void preorder(Node* n) {
	if(n != NULL) {
		printf("%3d", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(Node* n) {
	if(n != NULL) {
		inorder(n->left);
		printf("%3d", n->data);
		inorder(n->right);
	}
}

void postorder(Node* n) {
	if(n != NULL) {
		postorder(n->left);
		postorder(n->right);
		printf("%3d", n->data);
	}
}
