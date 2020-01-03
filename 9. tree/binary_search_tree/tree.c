#include "tree.h"

Node* createNode(Element e) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = e;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void addChild(Node* parent, Node* child) {
	if(child->data < parent->data) {
		if(parent->left != NULL) {
			addChild(parent->left, child);
		} else {
			parent->left = child;
		}
	} else {
		if(parent->right != NULL) {
			addChild(parent->right, child);
		} else {
			parent->right = child;
		}
	}
}

void print(Node* root) {
	printf("\n==== preorder print ====\n");
	preorder(root);
	printf("\n");
}

void preorder(Node* n) {
	if(n != NULL) {
		printf("%3d", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

Node* findMax(Node* n) {
	if(n->right == NULL)
		return n;
	else 
		return findMax(n->right);
}

Node* findMin(Node* n) {
	if(n->left == NULL) {
		return n;
	} else {
		return findMin(n->left);
	}
}

void freeNode(Node* n) {
	if(n != NULL) {
		freeNode(n->left);
		freeNode(n->right);
		free(n);
	}
}

void deleteNode(Node* n, Element data) {
	if(n!= NULL) {
		if(n->data == data) {
			if(n->left == NULL && n->right == NULL) {
				freeNode(n);
			} else if(n->left != NULL && n->right != NULL) {
				Node* leftMax = findMax(n->left);
				n->data = leftMax->data;
				freeNode(leftMax);
			} else if(n->left != NULL) {
				Node* tmp = n;
				n = n->left;
				freeNode(tmp);
			} else {
				Node* tmp = n;
				n = n->right;
				freeNode(tmp);
			}
		} else if(n->data > data) {
			deleteNode(n->left, data);
		} else {
			deleteNode(n->right, data);
		}
	} else {
		printf("* Error. No Match for %d.\n", data);
	}
}

