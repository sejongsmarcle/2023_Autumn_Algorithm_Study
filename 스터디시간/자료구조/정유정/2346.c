#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
typedef struct Balloon {
    int order;
    int value;
    struct Balloon* next;
    struct Balloon* prev;
} Balloon;

typedef struct {
    Balloon* front;
    Balloon* rear;
    int size;
} CircularQueue;

// 원형 큐 초기화 함수
void initQueue(CircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// 풍선 추가
void enqueue(CircularQueue* queue, int order, int value) {
    Balloon* newBalloon = (Balloon*)malloc(sizeof(Balloon));
    newBalloon->order = order;
    newBalloon->value = value;

    if (queue->size == 0) {
        newBalloon->next = newBalloon;
        newBalloon->prev = newBalloon;
        queue->front = newBalloon;
        queue->rear = newBalloon;
    }
    else {
        newBalloon->next = queue->front;
        newBalloon->prev = queue->rear;
        queue->rear->next = newBalloon;
        queue->front->prev = newBalloon;
        queue->rear = newBalloon;
    }

    queue->size++;
}

// 풍선 이동
void moveBalloon(CircularQueue* queue, int count) {
    if (count > 0) {
        for (int i = 1; i < count; i++) {
            queue->front = queue->front->next;
            queue->rear = queue->rear->next;
        }
    }
    else {
        for (int i = 0; i < -count; i++) {
            queue->front = queue->front->prev;
            queue->rear = queue->rear->prev;
        }
    }
}

// 풍선 제거
void popBalloon(CircularQueue* queue, int* order, int* value) {
    if (queue->size == 0) {
        *order = -1;
        *value = -1;
        return;
    }

    *order = queue->front->order;
    *value = queue->front->value;

    Balloon* temp = queue->front;
    if (queue->size == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        queue->front = temp->next;
        queue->rear->next = queue->front;
        queue->front->prev = queue->rear;
    }

    free(temp);
    queue->size--;
}

int main() {
    int N, n, m;
    scanf("%d", &N);

    CircularQueue queue;
    initQueue(&queue);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        enqueue(&queue, i, n);
    }

    int order, value;

    while (queue.size > 0) {
        printf("%d ", queue.front->order+1);
        m = queue.front->value;
        popBalloon(&queue, &order, &value);
        if (queue.size == 0) break;
        moveBalloon(&queue, m);
    }

    return 0;
}