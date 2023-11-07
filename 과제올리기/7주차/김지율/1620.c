#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef struct Node {
    int num;
    char name[20];
    struct Node* parent;
    struct Node* lChild;
    struct Node* rChild;
} Node;

Node* root;

int isInternal(Node* w);
int isExternal(Node* w);
void insertItem(int num, char name[]);
Node* treeSearch(Node* w, int num);
Node* treeSearchName(Node* w, char name[]);
Node* expandExternal(Node* z);
void findName(char input[]);
void findNum(char input[]);

int main() {

    char name[20] = { '\0' }, input[20] = { '\0' };
    int N, M, i;

    root = (Node*)malloc(sizeof(Node));
    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    scanf("%d %d", &N, &M);
    getchar();

    for (i = 0; i < N; i++) {
        scanf("%19s", name);
        insertItem(i + 1, name);
    }

    for (i = 0; i < M; i++) {
        scanf("%s", input);
        if ('0' <= input[0] && input[0] <= '9')
            findName(input);
        else
            findNum(input);
    }

    free(root);

    return 0;

}

int isInternal(Node* w) {
    if (w->lChild != NULL || w->rChild != NULL)
        return true;
    else
        return false;
}

int isExternal(Node* w) {
    if (w->lChild == NULL && w->rChild == NULL)
        return true;
    else
        return false;
}

void insertItem(int num, char name[]) {

    Node* w = treeSearch(root, num);

    if (isInternal(w))
        return;
    else {
        expandExternal(w);
        w->num = num;
        strcpy(w->name, name);
        return;
    }
}

Node* treeSearch(Node* w, int num) {
    if (isExternal(w))
        return w;
    if (num == w->num)
        return w;
    else if (num < w->num)
        return treeSearch(w->lChild, num);
    else
        return treeSearch(w->rChild, num);
}

Node* treeSearchName(Node* w, char name[]) {

    if (isExternal(w))
        return w;

    int cmp = strcmp(name, w->name);
    if (cmp == 0)
        return w;
    else if (cmp < 0)
        return treeSearchName(w->lChild, name);
    else
        return treeSearchName(w->rChild, name);

}

Node* expandExternal(Node* z) {

    Node* L = (Node*)malloc(sizeof(Node));
    Node* R = (Node*)malloc(sizeof(Node));

    L->lChild = NULL;
    L->rChild = NULL;
    L->parent = z;

    R->lChild = NULL;
    R->rChild = NULL;
    R->parent = z;

    z->lChild = L;
    z->rChild = R;

    return z;
}

void findName(char input[]) {

    int num = strtol(input, NULL, 10);

    Node* w = treeSearch(root, num);
    if (isExternal(w))
        printf("external\n");
    else
        printf("%s\n", w->name);
}

void findNum(char input[]) {

    Node* w = treeSearchName(root, input);
    if (isExternal(w))
        printf("external\n");
    else
        printf("%d\n", w->num);

}