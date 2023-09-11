/*

// 스택

#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include<stdio.h>
#include<string.h>
#define MAX_NUM 1000000

typedef struct number {
	int NUM;
}num;

typedef num Element;
Element data[MAX_NUM];
int top;

void error(char str[]) {
	printf("%s", str);
}

void init_stack() {
	top = -1;
}

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_NUM - 1;
}

int size() {
	if (top <= -1) {
		return 0;
	}
	else {
		return top + 1;
	}

}

void push(Element s) {

	data[++top] = s;
}

Element pop() {

	if (top <= -1) {
		top = 0;
		printf("-1\n");

	}
	else {
		printf("%d\n", data[top]);
	}

	return data[top--];

}

Element peek() {
	if (is_empty()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", data[top]);
	}

	return data[top];
}

num get_num(int number) {
	num N;
	N.NUM = number;

	return N;
}

int main() { // 러닝타임 에러 .. why ?
	int scale, n;
	int i = 0;
	char a[100];

	init_stack();

	scanf("%d", &scale);

	for (i = 0; i < scale; i++) {


		scanf("%s", &a);
		getchar();

		if (strcmp(a, "push") == 0) { // strcmp !!!
			scanf("%d", &n);
			push(get_num(n));
		}
		else if (strcmp(a, "pop") == 0) {
			pop();
		}
		else if (strcmp(a, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(a, "empty") == 0) {
			printf("%d\n", is_empty());
		}
		else if (strcmp(a, "top") == 0) {
			peek();
		}


	}

	return 0;

}



#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{

	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);

	printf("%d->", p->data);

}

ListNode* insert_first(ListNode* head, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}


ListNode* insert_last(ListNode* head, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* search_Node(ListNode* head,int n) {
	int cnt = 0;

	if (head == NULL) {
		return NULL;
	}
	else {
		ListNode* temp = head;

		while (temp->data != n) {
			cnt++;
			temp = temp->link;
		}
		printf("%d", cnt);

		return temp;
	}
}


int main() {
	ListNode* head = NULL;

	int a,n, p = 0;

	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf("%d", &n);
		head = insert_first(head, n);
	}

	ListNode* pop = head;

	for (int i = 0; i < a; i++) {

		printf("%d", pop->data);
		for (int j = 0; j < pop->data; j++) {
			pop = pop->link;
		}
		
	}

	return 0;
}

*/

// 큐

#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int cnt;
}Quene;


void init_quene(Quene* q) {
	q->front = q->rear = NULL;
	q->cnt = 0;
}

int is_empty(Quene* q) { // empty
	return q->cnt == 0;
}

void push(Quene* q, int data) { // enquene
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;

	if (is_empty(q)) {
		q->front = new;
	}
	else {
		q->rear->next = new;
	}
	q->rear = new;
	q->cnt++;
}

int pop(Quene* q) { // dequene
	int data;
	Node* a;

	if (is_empty(q)) {
		return -1;
	}
	a = q->front;
	data = a->data;
	q->front = a->next;
	free(a);
	q->cnt--;

	return data;
}

int size(Quene* q) {
	return q->cnt;
}

int front(Quene* q) {
	if (is_empty(q)) {
		return -1;
	}
	else {
		return q->front->data;
	}
}

int back(Quene* q) {
	if (is_empty(q)) {
		return -1;
	}
	else {
		return q->rear->data;
	}
}

int main() {

	Quene q;

	init_quene(&q);

	int a, num;
	char m[100] = {0};
	
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {

		scanf("%s", m);

		if (strcmp(m, "push") == 0) {
			scanf("%d", &num);
			push(&q, num);
		}
		else if (strcmp(m, "pop") == 0) {
			printf("%d\n", pop(&q));
		}
		else if (strcmp(m, "size") == 0) {
			printf("%d\n", size(&q));
		}
		else if (strcmp(m, "empty") == 0) {
			printf("%d\n", is_empty(&q));
		}
		else if (strcmp(m, "front") == 0) {
			printf("%d\n", front(&q));
		}
		else if (strcmp(m, "back") == 0) {
			printf("%d\n", back(&q));
		}

	}

	return 0;
}
