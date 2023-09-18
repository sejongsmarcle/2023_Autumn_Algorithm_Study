#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct listnode {
	int n;
	struct listnode* next;
}listnode;

typedef struct {
	listnode* H;
}listtype;

listnode* node() {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->next = NULL;
	return p;
}

void init(listtype* L) {
	L->H = NULL;
}

void add(listtype* L, int e) {
	listnode* p = node();
	p->n = e;
	if (L->H == NULL) {
		L->H = p;
	}
	else {
		listnode* q = L->H;
		if (q->n > p->n) {
			p->next = q;
			L->H = p;
		}
		else {
			while ((q->next != NULL) && (q->next->n < p->n)) { // 
				q = q->next;
			}
			p->next = q->next;
			q->next = p;
		}
	}
}

void mid(listtype* L, int n) {
	int k = n / 2;
	listnode* p = L->H;
	for (int i = 0; i < k; i++) {
		p = p->next;
	}
	printf("%d ", p->n);
}

void deleteAll(listtype* L) {
	for (listnode* p = L->H; p != NULL; p = p->next) {
		printf("%d ", p->n);
	}
}

void print(listtype* L) {
	for (listnode* p = L->H; p != NULL; p = p->next) {
		printf("%d ", p->n);
	}
}


int main() {

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		listtype L;
		init(&L);

		int n;
		scanf("%d", &n);
		printf("%d\n", n / 2 + 1);
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			add(&L, tmp);
			if ((i + 1) % 2 != 0) {
				mid(&L, i + 1);
			}
		}
		printf("\n");
	}

	return 0;
}
