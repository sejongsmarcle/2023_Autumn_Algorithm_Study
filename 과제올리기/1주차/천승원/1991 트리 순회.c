#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct treenode {
	char key;
	struct treenode* left;
	struct treenode* right;
}treenode;

treenode* makenode(char key) {
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

treenode* insertnode(treenode* root, char a, char b, char c) {
	if (root == NULL)
		return NULL;

	if (root->key == a) {
		if (b != '.')
			root->left = makenode(b);
		if (c != '.')
			root->right = makenode(c);
		return root;
	}
	else {
		treenode* p = insertnode(root->left, a, b, c);
		if (p != NULL)
			return p;
		return insertnode(root->right, a, b, c);
	}
}

void print1(treenode* root) {
	if (root) {
		printf("%c", root->key);
		print1(root->left);
		print1(root->right);
	}
}

void print2(treenode* root) {
	if (root) {
		print2(root->left);
		printf("%c", root->key);
		print2(root->right);
	}
}

void print3(treenode* root) {
	if (root) {
		print3(root->left);
		print3(root->right);
		printf("%c", root->key);
	}
}

int main()
{
	treenode* root;

	int n;
	scanf("%d\n", &n);

	char a, b, c;
	scanf("%c %c %c\n", &a, &b, &c);
	root = makenode(a);
	if (b != '.')
		root->left = makenode(b);
	if (c != '.')
		root->right = makenode(c);

	for (int i = 1; i < n - 1; i++) {
		scanf("%c %c %c\n", &a, &b, &c);
		insertnode(root, a, b, c);
	}

	print1(root);
	printf("\n");
	print2(root);
	printf("\n");
	print3(root);
	printf("\n");

	return 0;
}
