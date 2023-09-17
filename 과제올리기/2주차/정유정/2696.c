#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10000

// 구조체 선언
typedef int element;
typedef struct {
    int back;
    int count;
    element data[MAX_QUEUE_SIZE];
} QueueType;

// 큐 초기화
void init_queue(QueueType* q) {
    q->back = -1;
    q->count = 0;
}

// 정수 item을 큐에 넣는 연산
void push(QueueType* q, int item) {
    q->back = (q->back + 1) % MAX_QUEUE_SIZE;
    q->data[q->back] = item;
    q->count++;
}

// 삽입 정렬
void insertionSort(QueueType* q, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = q->data[i];
        j = i - 1;

        while (j >= 0 && q->data[j] > key) {
            q->data[j + 1] = q->data[j];
            j = j - 1;
        }
        q->data[j + 1] = key;
    }
}

int main() {

    int n, m, l, cnt = 0;
    QueueType q;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        init_queue(&q);
        scanf("%d", &m);
        cnt = 0;

        for (int j = 0; j < m; j++) {
            scanf("%d", &l);
            push(&q, l);
        }
        if (m % 2 == 0) printf("%d\n", m/2);
        else printf("%d\n", m / 2 + 1);

        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                insertionSort(&q, j + 1);
                printf("%d ", q.data[j / 2]);
                cnt++;
                if (cnt % 10 == 0) printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}