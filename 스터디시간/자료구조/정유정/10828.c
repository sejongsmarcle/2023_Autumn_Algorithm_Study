#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

// 스택 요소의 자료형 정의
typedef int element;

element data[MAX_STACK_SIZE];
int top;

// 스택 초기화
void init_stack() { top = -1; }

// 스택이 비어있으면 1, 아니면 0 반환
int empty() {
    return (top == -1);
}

// 정수 e를 스택에 넣는 연산
void pushX(element e) {
	 data[++top] = e;
}

// 가장 위에 있는 원소 반환, 제거
int pop() {
    if (empty()) return -1;
	else return data[top--];
}

// 스택에 있는 원소 수 반환
int size() {
    if (empty()) return 0;
	else return (top + 1);
}

// 가장 위에 있는 원소 반환
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