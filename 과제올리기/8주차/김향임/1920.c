#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10001

typedef struct NODE {
    int data;
    struct NODE* NEXT;
} node;

int M;
node* HashTable;

int hashFunction(int key) {
    if (key < 0) {
        key *= -1;
    }
    return key % SIZE;
}

void insertItem(int k) {
    int v = hashFunction(k);
    node* n, * p;
    n = (node*)malloc(sizeof(node));
    n->data = k;
    n->NEXT = NULL;

    p = HashTable + v;

    // 삽입 시 충돌이 발생하는 경우, 해당 버켓 리스트의 맨 앞에 삽입
    n->NEXT = p->NEXT;
    p->NEXT = n;
}

void FindItem(int k) {
    int f = 0;
    int v = hashFunction(k);

    node* p;
    p = HashTable + v;

    int cnt = 0;

    while (1) {
        if (p->NEXT == NULL) {
            cnt = 0;
            break;
        }
        p = p->NEXT;
        cnt++;
        if (p->data == k) {
            f = 1;
            break;
        }
    }

    if (cnt > 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

int main() {
    int k, N;

    scanf("%d", &M);

    HashTable = (node*)malloc(sizeof(node)*SIZE );

    for (int i = 0; i < SIZE ; i++) {
        HashTable[i].data = 0;
        HashTable[i].NEXT = NULL;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &k);
        insertItem(k);
    }

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &k);
        FindItem(k);
    }

    free(HashTable);

    return 0;
}
