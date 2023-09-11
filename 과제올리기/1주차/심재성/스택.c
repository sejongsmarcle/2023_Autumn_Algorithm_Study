#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* top;
	int size;
} Stack;

void initStack(Stack* stack) {
	stack->top = NULL;
	stack->size = 0;
}

int empty(Stack* stack) {
	if (stack->top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(Stack* stack, int N) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = N;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("-1\n");
		return -1;
	}
	else {
		Node* temp = stack->top;
		int N = temp->data;
		stack->top = stack->top->next;
		stack->size--;
		free(temp);
		printf("%d\n", N);
		return N;
	}
}

int size(Stack* stack) {
	printf("%d\n", stack->size);
	return stack->size;
}

int top(Stack* stack) {
	if (stack->top == NULL) {
		printf("-1\n");
		return -1;
	}
	else {
		printf("%d\n", stack->top->data);
		return stack->top->data;
	}
}

int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack);

	int cnt;
	scanf("%d", &cnt);
	getchar();

	while (cnt > 0) {
		char cmd[6];
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0) {
			int N;
			scanf("%d", &N);
			getchar();
			push(stack, N);
			cnt--;
		}
		else if (strcmp(cmd, "pop") == 0) {
			pop(stack);
			cnt--;
		}
		else if (strcmp(cmd, "size") == 0) {
			size(stack);
			cnt--;
		}
		else if (strcmp(cmd, "empty") == 0) {
			printf("%d\n", empty(stack));
			cnt--;
		}
		else if (strcmp(cmd, "top") == 0) {
			top(stack);
			cnt--;
		}
	}

	free(stack);
	return 0;
}
