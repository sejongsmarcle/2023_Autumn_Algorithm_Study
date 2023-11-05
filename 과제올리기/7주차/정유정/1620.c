#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
	char mon[21];
	int num;
	struct Tree* left;
	struct Tree* right;
};

struct Tree* root = NULL;

struct Tree* createNode(int i, char* ch) {
	struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->num = i;
	strcpy(newNode->mon, ch);
	return newNode;
}

void insertMon(int i, char* ch) {
	if (root == NULL)
		root = createNode(i, ch);
	else {
		struct Tree* w = root;
		while (1) {
			if (i < w->num) {
				if (w->left == NULL) {
					w->left = createNode(i, ch);
					break;
				}
				w = w->left;
			}
			else {
				if (w->right == NULL) {
					w->right = createNode(i, ch);
					break;
				}
				w = w->right;
			}
		}
	}
}

struct Tree* treeSearchMon(struct Tree* w, int n) {
	if (w == NULL) return w;
	if (w->num == n) return w;
	else if (w->num > n) return treeSearchMon(w->left, n);
	else return treeSearchMon(w->right, n);
}

char* findMon(int n) {
	struct Tree* w = treeSearchMon(root, n);
	return w->mon;
}

struct Tree* treeSearchNum(struct Tree* w, char* ch) {
	if (w == NULL) return NULL;
	if (strcmp(w->mon, ch) == 0) return w;
	struct Tree* leftRes = treeSearchNum(w->left, ch);
	if (leftRes != NULL) return leftRes;
	return treeSearchNum(w->right, ch);
}

int findNumber(char* ch) {
	struct Tree* w = treeSearchNum(root, ch);
	return w->num;
}

int main() {

	int n, m;
	char ch[21], ans[21];
	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i < n; i++) {
		gets(ch);
		insertMon(i, ch);
	}

	for (int i = 0; i < m; i++) {
		gets(ans);
		if (ans[0] >= '0' && ans[0] <= '9') {
			int num = atoi(ans);
			printf("%s\n", findMon(num - 1));
		}
		else
			printf("%d\n", findNumber(ans) + 1);
	}

	return 0;
}