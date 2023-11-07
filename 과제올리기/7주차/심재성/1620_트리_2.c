#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char name[21];
	int number;
	struct Node* left;
	struct Node* right;
};

struct Node* insert(struct Node* root, char* name, int number, int index) {
	if (root == NULL) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy(newNode->name, name);
		newNode->number = number;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (index % 2 == 1) {
		root->left = insert(root->left, name, number, index / 2);
	}
	else {
		root->right = insert(root->right, name, number, index / 2);
	}

	return root;
}

struct Node* searchByNumber(struct Node* root, int number) {
	if (root == NULL || root->number == number) {
		return root;
	}

	struct Node* leftResult = searchByNumber(root->left, number);
	if (leftResult != NULL) {
		return leftResult;
	}

	struct Node* rightResult = searchByNumber(root->right, number);
	return rightResult;
}

struct Node* searchByName(struct Node* root, char* name) {
	if (root == NULL) {
		return NULL;
	}

	if (strcmp(root->name, name) == 0) {
		return root;
	}

	struct Node* leftResult = searchByName(root->left, name);
	if (leftResult != NULL) {
		return leftResult;
	}

	struct Node* rightResult = searchByName(root->right, name);
	return rightResult;
}

void freeTree(struct Node* root) {
	if (root == NULL) {
		return;
	}

	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);

	struct Node* root = NULL;

	for (i = 0; i < N; i++) {
		char name[21];
		scanf("%s", name);
		root = insert(root, name, i + 1, i);
	}

	for (i = 0; i < M; i++) {
		char name[21];
		scanf("%s", name);
		if (name[0] >= '0' && name[0] <= '9') {
			int number = atoi(name);
			struct Node* result = searchByNumber(root, number);
			if (result != NULL) {
				printf("%s\n", result->name);
			}
		}
		else {
			struct Node* result = searchByName(root, name);
			if (result != NULL) {
				printf("%d\n", result->number);
			}
		}
	}

	freeTree(root);

	return 0;
}


