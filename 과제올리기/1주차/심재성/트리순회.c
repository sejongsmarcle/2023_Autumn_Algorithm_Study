#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} Node;

Node* input(char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void freeTree(Node* tree) {
	if (tree == NULL) {
		return;
	}
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
}

void preorder(Node* tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	preorder(tree->left);
	preorder(tree->right);
}

void inorder(Node* tree) {
	if (tree == NULL) {
		return;
	}
	inorder(tree->left);
	printf("%c", tree->data);
	inorder(tree->right);
}

void postorder(Node* tree) {
	if (tree == NULL) {
		return;
	}
	postorder(tree->left);
	postorder(tree->right);
	printf("%c", tree->data);
}

void addLeftRight(Node* tree, char value1, char value2, char value3) {
	if (tree == NULL) {
		return;
	}
	if (tree->data == value1) {
		if (value2 != '.') {
			tree->left = input(value2);
		}
		if (value3 != '.') {
			tree->right = input(value3);
		}
	}
	addLeftRight(tree->left, value1, value2, value3);
	addLeftRight(tree->right, value1, value2, value3);
}

int main() {
	int N;
	scanf("%d", &N);

	char value1, value2, value3;

	Node* root = input('A'); 

	for (int i = 0; i < N; i++) {
		scanf(" %c %c %c", &value1, &value2, &value3);
		addLeftRight(root, value1, value2, value3);
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);

	freeTree(root);

	return 0;

}
