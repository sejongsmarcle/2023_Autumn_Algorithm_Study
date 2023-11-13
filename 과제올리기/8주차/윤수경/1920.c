#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)


#define TABLE_SIZE 100000

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable;

void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        (hashTable + i)->next = NULL;
    }
}

int h(int k) {
    return abs(k) % TABLE_SIZE;
}

void insertItem(int x) {
    int v = h(x);

    Node* p = hashTable + v;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = x;
    newnode->next = p->next;
    p->next = newnode;
}

int searchItem(int x) {
    int v = h(x);
    Node* p = hashTable + v;

    while (p->next != NULL) {
        p = p->next;
        if (p->key == x) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int N, M;

    scanf("%d", &N);
    hashTable = (Node*)malloc(sizeof(Node) * TABLE_SIZE);
    init();

    int key;

    for (int i = 0; i < N; i++) {
        scanf("%d", &key);
        insertItem(key);
    }

    scanf("%d", &M);
    int num;
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        if (searchItem(num) == 1) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }



    free(hashTable);

    return 0;
}

