#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    char name[21];
    struct Node* lChild;
    struct Node* rChild;
} Node;

Node* tree;

Node* treeInsert(Node* root, int k, char* name) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = k;
        strcpy(newNode->name, name);
        newNode->lChild = NULL;
        newNode->rChild = NULL;
        return newNode;
    }

    if (strcmp(name, root->name) < 0) {
        root->lChild = treeInsert(root->lChild, k, name);
    }
    else {
        root->rChild = treeInsert(root->rChild, k, name);
    }

    return root;
}

Node* treeSearch(Node* n, int k) {
    if (n == NULL)
        return NULL;

    if (k == n->key) {
        return n;
    }
    else if (k < n->key) {
        return treeSearch(n->lChild, k);
    }
    else {
        return treeSearch(n->rChild, k);
    }
}

Node* nameSearch(Node* root, char* name) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->name);

    if (cmp == 0) {
        return root;
    }
    else if (cmp < 0) {
        return nameSearch(root->lChild, name);
    }
    else {
        return nameSearch(root->rChild, name);
    }
}

int main() {
    int n, m;
    char input[21];

    scanf("%d %d", &n, &m);

    tree = NULL;

    for (int i = 1; i <= n; i++) {
        char name[21];
        scanf("%s", name);
        tree = treeInsert(tree, i, name);
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", input);

        if (input[0] >= '0' && input[0] <= '9') {
            int id = atoi(input);
                Node* result = treeSearch(tree, id);
                if (result != NULL) {
                    printf("%s\n", result->name);
                }
               
        }
        else {
            Node* result = nameSearch(tree, input);
            if (result != NULL) {
                printf("%d\n", result->key);
            }
           
        }
    }


    return 0;
}

