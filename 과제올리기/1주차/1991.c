#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    char data;
    struct TNode* left;
    struct TNode* right;
} TNode;

TNode* create_tree(char item) {
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = item;
    n->left = NULL;
    n->right = NULL;
    return n;
}

TNode* find_node(TNode* n, char item) {
    if (n == NULL || n->data == item) {
        return n;
    }

    TNode* left_result = find_node(n->left, item);
    if (left_result != NULL) {
        return left_result;
    }

    TNode* right_result = find_node(n->right, item);
    if (right_result != NULL) {
        return right_result;
    }

    return NULL;
}

void build_tree(TNode* root, char parent, char left, char right) {
    TNode* parentNode = find_node(root, parent);

    if (parentNode != NULL) {
        if (left != '.') {
            parentNode->left = create_tree(left);
        }
        if (right != '.') {
            parentNode->right = create_tree(right);
        }
    }
}

void preorder(TNode* n) {
    if (n != NULL) {
        printf("%c", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}

void inorder(TNode* n) {
    if (n != NULL) {
        inorder(n->left);
        printf("%c", n->data);
        inorder(n->right);
    }
}

void postorder(TNode* n) {
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        printf("%c", n->data);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    TNode* root = create_tree('A');

    for (int i = 0; i < n; i++) {
        char p, l, r;
        scanf("%c %c %c", &p, &l, &r);
        getchar();

        build_tree(root, p, l, r);
    }

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}