#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

// ���� ����� �ڷ��� ����
typedef int element;

element data[MAX_STACK_SIZE];
int top;

// ���� �ʱ�ȭ
void init_stack() { top = -1; }

// ������ ��������� 1, �ƴϸ� 0 ��ȯ
int empty() {
    return (top == -1);
}

// ���� e�� ���ÿ� �ִ� ����
void pushX(element e) {
	 data[++top] = e;
}

// ���� ���� �ִ� ���� ��ȯ, ����
int pop() {
    if (empty()) return -1;
	else return data[top--];
}

// ���ÿ� �ִ� ���� �� ��ȯ
int size() {
    if (empty()) return 0;
	else return (top + 1);
}

// ���� ���� �ִ� ���� ��ȯ
int peek() {
    if (empty()) return -1;
	else return data[top];
}

int main() {

	int n, m;
	char ch[7];
    init_stack();
	scanf("%d", &n);
	getchar();

    for (int i = 0; i < n; i++) {
        scanf("%s", ch);
        if (strcmp(ch, "push") == 0) {
            scanf("%d", &m);
            pushX(m);
        }
        else if (strcmp(ch, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(ch, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(ch, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(ch, "top") == 0) {
            printf("%d\n", peek());
        }
    }

	return 0;
}