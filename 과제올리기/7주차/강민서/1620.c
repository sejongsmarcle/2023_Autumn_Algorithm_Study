#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

struct TreeNode {
    int key;
    char name[21];
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insert(struct TreeNode* root, int key, const char* name) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->key = key;
        strncpy(newNode->name, name, sizeof(newNode->name));
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key) {
        root->left = insert(root->left, key, name);
    }
    else {
        root->right = insert(root->right, key, name);
    }


    return root;
}

int searchByName(struct TreeNode* root, const char* name) {
    if (root == NULL) {
        return -1; // 찾지 못한 경우
    }

    int cmp = strcmp(name, root->name);
    if (cmp == 0) {
        return root->key;
    }
    else if (cmp < 0) {
        return searchByName(root->left, name);
    }
    else {
        return searchByName(root->right, name);
    }
}

char* searchByNumber(struct TreeNode* root, int key) {
    if (root == NULL) {
        return "X"; // 찾지 못한 경우
    }

    if (key == root->key) {
        return root->name;
    }
    else if (key < root->key) {
        return searchByNumber(root->left, key);
    }
    else {
        return searchByNumber(root->right, key);
    }
}

void quickSort(struct TreeNode* root, int l, int r) {
    int a, b;
    if (l >= r)
        return;
    a = b = inPlacePartition(root, l, r, r);
    quickSort(root, l, a - 1);
    quickSort(root, b + 1, r);
}

int inPlacePartition(struct TreeNode* root, int l, int r, int k) {
    struct TreeNode p;
    struct TreeNode tmp;
    int i, j;
    p = root[k];

    tmp = root[k];
    root[k] = root[r];
    root[r] = tmp;

    i = l; j = r - 1;

    while (i <= j) {
        while (i <= j && strcmp(root[i].name, p.name) <= 0) {
            i++;
        }
        while (i <= j && strcmp(root[i].name, p.name) >= 0) {
            j--;
        }
        if (i < j) {
            tmp = root[i];
            root[i] = root[j];
            root[j] = tmp;
        }
    }
    tmp = root[i];
    root[i] = root[r];
    root[r] = tmp;
    return i;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    struct TreeNode* root = NULL;

    for (int i = 1; i <= N; i++) {
        char name[21];
        scanf("%s", name);
        root = insert(root, i, name);
    }

    while (M--) {
        char question[21];
        scanf("%s", question);

        if (isdigit(question[0])) {//숫자일 경우
            int key = atoi(question);
            printf("%s\n", searchByNumber(root, key));
        }
        else { //문자일 경우
            quickSort(root, 0, N - 1);
            printf("%d\n", searchByName(root, question));
        }
    }

    return 0;
}
