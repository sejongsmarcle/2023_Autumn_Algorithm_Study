#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100000

// ����ü ����
typedef int element;
typedef struct {
    int front;
    int back;
    int count;
    element data[MAX_QUEUE_SIZE];
} QueueType;

// ť �ʱ�ȭ
void init_queue(QueueType* q) {
    q->back = -1;
    q->front = 0;
    q->count = 0;
}

// ť�� ��������� 1, �ƴϸ� 0�� ���
int is_empty(QueueType* q) {
    if (q->count == 0)
        return 1;

    else
        return 0;
}

// ���� item�� ť�� �ִ� ����
void push(QueueType* q, int item) {
    q->back = (q->back + 1) % MAX_QUEUE_SIZE;
    q->data[q->back] = item;
    q->count++;
}

// ť���� ���� �տ� �ִ� ������ ����, �� ���� ���
void pop(QueueType* q) {
    if (is_empty(q) == 1)
        printf("-1\n");
    else {
        int item = q->data[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->count--;
        printf("%d\n", item);
    }
}

// ť�� ��������� 1, �ƴϸ� 0�� ���
void empty(QueueType* q) {
    if (is_empty(q) == 1)
        printf("1\n");
    
    else
        printf("0\n");
}

// ť�� ���� �տ� �ִ� ������ ���
void front(QueueType* q) {
    if (is_empty(q) == 1)
        printf("-1\n");

    else {
        printf("%d\n", q->data[q->front]);
    }
}

// ť�� ���� �ڿ� �ִ� ������ ���
void back(QueueType* q) {
    if (is_empty(q) == 1)
        printf("-1\n");

    else {
        printf("%d\n", q->data[q->back]);
    }
}

// ť�� ����ִ� ������ ������ ���
void size(QueueType* q) {
    printf("%d\n", q->count);
}

int main() {

    int n, m;
    char ch[10];
    QueueType q;

    init_queue(&q);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", ch);
        if (strcmp(ch, "push") == 0) {
            scanf("%d", &m);
            push(&q, m);
        }
        else if (strcmp(ch, "pop") == 0) {
            pop(&q);
        }
        else if (strcmp(ch, "size") == 0) {
            size(&q);
        }
        else if (strcmp(ch, "empty") == 0) {
            empty(&q);
        }
        else if (strcmp(ch, "front") == 0) {
            front(&q);
        }
        else if (strcmp(ch, "back") == 0) {
            back(&q);
        }
    }
    
    return 0;
}
