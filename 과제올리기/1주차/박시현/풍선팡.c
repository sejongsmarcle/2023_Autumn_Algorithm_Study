#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct ListNode {
    int elem;
    int num;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;

typedef struct ListType {
    ListNode* T;
}ListType;

void init(ListType *);
void InsertLast(ListType* ,int,int);
void DeleteNode(ListType* );
void print(ListType *);

int main() {
    ListType L;
    int N;
    int i;
    int e;

    init(&L);

    scanf("%d", &N);

    //풍선 더미들 만듦.
    for (i = 0; i < N; i++) {
        scanf("%d", &e);
        InsertLast(&L, e,i);
    }

    DeleteNode(&L);

    return 0;
}

void init(ListType * L) {
    L->T = NULL;
}

void InsertLast(ListType* L, int e,int i) {
    //노드 한 개 생성
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->elem = e;
    node->num = i + 1;
    node->next = NULL;
    node->prev = NULL;

    //Insert
    if (L->T == NULL) {
        L->T = node;
        L->T->prev = node;
        L->T->next=node;
    }

    else {

        node->next = L->T->next;
        node->prev = L->T;

        L->T->next = node;
        if (L->T->prev == L->T)
            L->T->prev = node;

        L->T = node;
    }

}

void DeleteNode(ListType* L) {
    ListNode* p = L->T;
    ListNode* deleted = L->T->next; //첫번째 풍선
    int i;

    while (L->T!=NULL)
    {
        printf("%d ", deleted->num);

        //삭제를 할 거야.
        p->next = deleted->next;
        deleted->next->prev = p;

        if (deleted->elem > 0) {
            //이동을 할 거야. (양수일 때)
            for (i = 0; i < deleted->elem - 1; i++)
                p = p->next;
        }

        if (deleted->elem < 0) {
            //이동을 할 거야. (음수일 때)
            for (i = deleted->elem; i<0; i++)
                p = p->prev;
        }

        free(deleted);

        deleted = p->next;

        if (deleted == L->T)
            L->T = p;
    }
}

void print(ListType* L) {
    ListNode* p = L->T->next;
    for (; p != L->T; p = p->next) {
        printf(" %d", p->elem);
    }
    printf(" %d", p->elem);

}
