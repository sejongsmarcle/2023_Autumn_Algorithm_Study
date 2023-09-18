#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct listnode {
	int n;
	int k;
	struct listnode* prev;
	struct listnode* next;
}listnode;

typedef struct {
	listnode* T;
}listtype;

listnode* node() {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->next = p->prev = NULL;
	return p;
}

void init(listtype* L) {
	L->T = NULL;
}

void add(listtype* L, int e, int k) {
	listnode* p = node();
	p->n = e;
	p->k = k;

	if (L->T == NULL) {
		L->T = p;
		L->T->next = L->T->prev = p;
	}
	else {
		p->prev = L->T;			//새로 삽입하는 노드를 먼저 연결
		p->next = L->T->next;
		L->T->next->prev = p;	//그 다음 원래 노드들 연결 변경(L->T->next = L->H역할)
		L->T->next = p;
		L->T = p;				//마지막 테일 변경
	}
}

int delete(listnode* d, int arr[], int n) {	//처음엔 헤더와 테일을 이동시키는 방식으로 구현
	//but 백준 오류로 인해 삭제할 노드 자체의 위치를 움직이도록 함.
	if (d->next == d) {		
		//d == NULL(노드가 없을때를 뜻함)을 인식하질 못함. visual의 특징인듯
		//그래서 노드가 하나만 있을때(노드의 next, prev가 자기자신을 가리키고 있을때)를 조건으로 사용, 예외처리
		printf("%d", d->k);
		free(d);
		return 0;			//그래서 다른 조건 사용
	}
	else {
		d->next->prev = d->prev;		//d(삭제할 노드)의 연결을 끊음
		d->prev->next = d->next;
		int e = d->n;
		printf("%d ", d->k);

		listnode* p = d;
		if (e > 0) {
			for (int i = 0; i < e; i++) {
				p = p->next;
			}
		}
		else {
			e = 0 - e; //절댓값
			for (int i = 0; i < e; i++) {
				p = p->prev;
			}
		}

		free(d);

		return delete(p, arr, n);
	}
}

void print(listtype* L) {
	listnode* p = L->T->next;
	for (int i = 0; i < 7; i++) {
		printf("%d ", p->n);
		p = p->next;
	}
}

int main() {
	listtype L;
	init(&L);

	int n;
	scanf("%d", &n);
	int arr[1000];

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i] = tmp;
		add(&L, tmp, i + 1);
	}

	delete(L.T->next, arr, n);

	return 0;
}
