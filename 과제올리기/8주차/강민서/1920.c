#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int elem;
	struct node* next;
}NODE;

int N;
NODE* Table;

int h(int x) {
	return (x % N);
}

void insertItem(int x) {

	int v = h(x);
	NODE* p = Table + v;

	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->elem = x;
	new->next = p->next;
	p->next = new;
}



int searchItem(int x) {

	int v = h(x);
	int rank = 0;
	NODE* p = Table + v;

	if (p->next == NULL) {
		return 0;
	}
	else {
		while (1) {
			p = p->next;
			rank++;
			if (p->elem == x) {
				return rank;
			}
			if (p->next == NULL) {
				return 0;
			}
		}
	}
}


void freeTable() {

	NODE* p1, * p2;

	for (int i = 0; i < N; i++) {
		if ((Table + i)->next != NULL) {
			p1 = (Table + i)->next;
			p2 = p1;

			while (p2->next != NULL) {
				p1 = p1->next;
				free(p2);
				p2 = p1;
			}
		}
	}
	free(Table);
}

int main() {
	int key, M;
	char com;
	scanf("%d", &N);

	Table = (NODE*)malloc(sizeof(NODE) * N);
	for (int i = 0; i < N; i++) {
		(Table + i)->elem = 0;
		(Table + i)->next = NULL;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &key);
		insertItem(key); //삽입
	}
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &key);
		if (searchItem(key) == 0)
			printf("0\n");
		else
			printf("1\n");
	}

	freeTable();

	return 0;
}
