#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int element;

typedef struct stacknode {
	element elem;
	struct stacknode* next;
}stacknode;

typedef struct {
	stacknode* H;
	int n;
}stacktype;

stacknode* node() {
	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
	node->next = NULL;
	return node;
}

void init(stacktype* S) {
	S->H = node();
	S->n = 0;
}

int isEmpty(stacktype* S) {
	return S->H->next == NULL;
}

void push(stacktype* S, element e) {
	stacknode* p = node();
	p->elem = e;

	p->next = S->H->next;
	S->H->next = p;
	S->n++;
}

int pop(stacktype* S) {
	if (isEmpty(S)) {
		printf("-1\n");
		return 0;
	}
	element e = S->H->next->elem;
	stacknode* p = S->H->next;
	S->H->next = p->next;
	printf("%d\n", e);
	free(p);
	S->n--;
	return e;
}

void top(stacktype* S) {
	if (isEmpty(S)) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", S->H->next->elem);
}

void size(stacktype* S) {
	printf("%d\n", S->n);
}

void print(stacktype* S) {
	for (stacknode* p = S->H->next; p != NULL; p = p->next) {
		printf("%d ", p->elem);
	}
	printf("\n");
}

int main()
{
	stacktype S;
	init(&S);
	
	int num;
	scanf("%d", &num);

	char sts[100];
	for (int i = 0; i < num; i++) {
		scanf("%s", &sts);
		getchar();
		if (strcmp(sts, "pop") == 0) {
			pop(&S);
		}
		else if (strcmp(sts, "push") == 0) {
			int tmp;
			scanf("%d", &tmp);
			getchar();
			push(&S, tmp);
		}
		else if (strcmp(sts, "top") == 0) {
			top(&S);
		}
		else if (strcmp(sts, "size") == 0) {
			size(&S);
		}
		else if (strcmp(sts, "empty") == 0) {
			printf("%d\n", isEmpty(&S));
		}
	}

	return 0;
}
