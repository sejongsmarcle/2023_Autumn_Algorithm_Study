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

struct Node* insert(struct Node* node, char* name, int number) {
	if (node == NULL) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy(newNode->name, name);
		newNode->number = number;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (strcmp(name, node->name) < 0) {
		node->left = insert(node->left, name, number);
	}
	else if (strcmp(name, node->name) > 0) {
		node->right = insert(node->right, name, number);
	}

	return node;
}

struct Node* searchByName(struct Node* node, char* name) {
	if (node == NULL || strcmp(name, node->name) == 0) {
		return node;
	}

	if (strcmp(name, node->name) < 0) {
		return searchByName(node->left, name);
	}
	else {
		return searchByName(node->right, name);
	}
}

struct Node* searchByNumber(struct Node* node, int number) {
	if (node == NULL || node->number == number) {
		return node;
	}

	if (number < node->number) {
		return searchByNumber(node->left, number);
	}
	else {
		return searchByNumber(node->right, number);
	}
}

void freeTree(struct Node* node) {
	if (node == NULL) {
		return;
	}

	freeTree(node->left);
	freeTree(node->right);
	free(node);
}

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);

	struct Node* root = NULL;

	for (i = 0; i < N; i++) {
		char name[21];
		scanf("%s", name);
		root = insert(root, name, i + 1);
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

	getchar();

	return 0;
}

