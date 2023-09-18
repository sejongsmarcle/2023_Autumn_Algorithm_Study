#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* next;
}QueueNode;

typedef struct
{
	QueueNode* front;
	QueueNode* rear;
	int n;
}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = NULL;
	Q->n = 0;
}

int isEmpty(QueueType* Q) {
	return Q->front == NULL;
}

void push(QueueType* Q, element e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;

	if (isEmpty(Q))
		Q->front = Q->rear = node;
	else {
		Q->rear->next = node;
		Q->rear = node;
	}
	Q->n++;
}

element pop(QueueType* Q)
{
	if (isEmpty(Q)) {
		printf("-1\n");
		return 0;
	}
	QueueNode* p = Q->front;
	element e = p->data;
	Q->front = p->next;

	if (Q->front == NULL) //원소가 딱 한개밖에 없던 경우(?) 삭제시 원소가 없는 NULL값이 되므로 초기상태(init - 둘다 아무것도 안가리키는 상태)로 돌리기
		Q->rear = NULL; //rear는 마지막 노드 그대로 가리키고 있는 상태가 되므로 끊어주기 위해

	free(p);
	printf("%d\n", e);
	Q->n--;
	return e;
}

element front(QueueType* Q)
{
	if (isEmpty(Q)) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", Q->front->data);
	return Q->front->data;
}

element back(QueueType* Q)
{
	if (isEmpty(Q)) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", Q->rear->data);
	return Q->rear->data;
}

element size(QueueType* Q)
{
	printf("%d\n", Q->n);
	return Q->rear->data;
}

int main()
{
	QueueType Q;
	init(&Q);

	int num;
	scanf("%d", &num);

	char sts[100];
	for (int i = 0; i < num; i++) {
		scanf("%s", &sts);
		getchar();
		if (strcmp(sts, "pop") == 0) {
			pop(&Q);
		}
		else if (strcmp(sts, "push") == 0) {
			int tmp;
			scanf("%d", &tmp);
			getchar();
			push(&Q, tmp);
		}
		else if (strcmp(sts, "front") == 0) {
			front(&Q);
		}
		else if (strcmp(sts, "back") == 0) {
			back(&Q);
		}
		else if (strcmp(sts, "size") == 0) {
			size(&Q);
		}
		else if (strcmp(sts, "empty") == 0) {
			printf("%d\n", isEmpty(&Q));
		}
	}

	return 0;
}
