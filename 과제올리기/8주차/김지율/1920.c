#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define HASHTABLE_SIZE 10007

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int hash(int key) {
    return (key >= 0) ? (key % HASHTABLE_SIZE) : ((-key) % HASHTABLE_SIZE);
}

void insertKey(Node* table, int key) {

    int index = hash(key);
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) exit(1);
    new->data = key;
    new->next = table[index].next;
    table[index].next = new;

}

int searchKey(Node* table, int key) {

    int index = hash(key);
    Node* cur = table[index].next;

    while (cur != NULL) {
        if (cur->data == key) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;

}

int main() {

    int N, M, i, key;

    scanf("%d", &N);

    Node* table = (Node*)malloc(HASHTABLE_SIZE * sizeof(Node));
    if (table == NULL) exit(1);

    for (i = 0; i < HASHTABLE_SIZE; i++) {
        table[i].next = NULL;
        table[i].data = 0;
    }

    for (i = 0; i < N; i++) {
        scanf("%d", &key);
        insertKey(table, key);
    }

    scanf("%d", &M);

    for (i = 0; i < M; i++) {
        scanf("%d", &key);
        printf("%d\n", searchKey(table, key));
    }

    for (i = 0; i < HASHTABLE_SIZE; i++) {
        Node* cur = table[i].next;
        while (cur != NULL) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(table);

    return 0;
}