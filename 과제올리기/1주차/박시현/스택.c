#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct ListNode {
    int elem;
    struct ListNode* prev;
}ListNode;

typedef struct ListType {
    ListNode* T;
}ListType;

void init(ListType *);
void push(ListType*, int);
void pop(ListType*);
void size(ListType*);
void empty(ListType*);
void top(ListType*);


int main() {
    ListType L;
    int N, i;
    char type[6] = "";
    int elem;

    init(&L);

    scanf("%d", &N);

    //풍선 더미들 만듦.
    for (i = 0; i < N; i++) {
        scanf("%s", &type);

        if (strcmp(type, "push") == 0) {
            scanf("%d", &elem);
            push(&L, elem);
        }

        else if (strcmp(type, "pop") == 0)
            pop(&L);

        else if (strcmp(type, "size") == 0)
            size(&L);

        else if (strcmp(type, "empty") == 0)
            empty(&L);

        else if (strcmp(type, "top") == 0)
            top(&L);

    }

    return 0;
}

void init(ListType * L) {
    L->T = NULL;
}
void push(ListType* L, int e) {
    //노드 생성
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->elem = e;
    node->prev = NULL;

    //Top에서의 연결
    if(L->T !=NULL)
        node->prev= L->T;

    L->T = node;

}
void pop(ListType* L) {
    if (L->T == NULL) //비어있지 않으면
        printf("-1\n");
    else {        //비어 있으면
        ListNode* p = L->T;

        printf("%d\n", L->T->elem);
        L->T = p->prev;
        free(p);
    }
    

}

void size(ListType* L) {
    ListNode* p = L->T;
    int num=0;

    for (; p != NULL; p = p->prev)
        num++;

    printf("%d\n", num);
}

void empty(ListType* L) {
    if (L->T != NULL) //비어있지 않으면
        printf("0\n");
    else //비어 있으면
        printf("1\n");
}

void top(ListType* L) {
    if (L->T != NULL)
        printf("%d\n", L->T->elem);
    else
        printf("-1\n");

}
