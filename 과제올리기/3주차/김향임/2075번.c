#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
# include <time.h>
#define MAX_NUM 1500

typedef struct{
	int data;
}element;

typedef struct{
	element heap[MAX_NUM * MAX_NUM];
	int heap_size;
}HeapType;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void upHeap(HeapType* n, int i) {

	if (i == 1) return;

	if (n->heap[i].data > n->heap[i / 2].data) {
		swap(&(n->heap[i].data), &(n->heap[i / 2].data));
		i = i / 2;
		upHeap(n, i);
	}

}

void DownHeap(HeapType* n, int i) {

	int left = i * 2;
	int right = i * 2 + 1;

	if (left > n->heap_size) return;

	int larger = left;

	if (n->heap[larger].data < n->heap[right].data) {
		larger = right;
	}

	if (n->heap[larger].data > n->heap[i].data) {
		swap(&(n->heap[larger].data), &(n->heap[i].data));
	}

	DownHeap(n, larger);

}

void insertHeap(HeapType* n, int a) {
	n->heap_size++;
	n->heap[n->heap_size].data = a;
	upHeap(n, n->heap_size);

	return;
}

int removeHeap(HeapType* n) {
	int key = n->heap[1].data;
	n->heap[1].data = n->heap[n->heap_size].data;
	n->heap_size--;
	DownHeap(n, 1);

	return key;
}

int main() {
	

	int N, a;

	scanf("%d", &N);

	HeapType* m = (HeapType*)malloc(sizeof(HeapType));	

	m->heap_size = 0;

	for (int i = 1; i < N*N + 1; i++) {
		scanf("%d", &a);
		insertHeap(m, a);
	}

	for (int i = 1; i <= N; i++) {
		int b = removeHeap(m);

		if (i == N) {
			printf("%d ", b);
		}
	}
	
	return 0;

}
