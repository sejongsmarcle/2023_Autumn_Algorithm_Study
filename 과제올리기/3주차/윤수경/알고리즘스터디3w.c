#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
//실패..하지만 페어와 해개ㅕㄹ해보겠어

#define SIZE 225000


typedef struct {
	int Heap[SIZE];
	int n;
}Heap;

void init(Heap* heap, int n) {
	heap->n = n;
}

void insertItem(Heap* heap, int i, int k) {
	heap->Heap[i] = k;
	

}
void downHeap(Heap* heap, int i) {
	int down = i * 2;
	int n = heap->n;
	//왼쪽 오른쪽 비교
	if ((n < (i * 2)) && (n < (i * 2 + 1))) {
		return;
	}//downheap 끝

	//오른쪽
	if (n >= i * 2 + 1) {
		if (heap->Heap[i * 2 + 1] > heap->Heap[down]) {
			down = i * 2 + 1;
		}
	}

	//삽입 노드와 자식 노드 비교
	if (heap->Heap[i] >= heap->Heap[down]) return;

	int tmp;
	tmp = heap->Heap[i];
	heap->Heap[i] = heap->Heap[down];
	heap->Heap[down] = tmp;

	downHeap(heap, down);
}
void root(Heap* heap, int s) {
	int temp = heap->Heap[1];
	heap->Heap[1] = heap->Heap[s];
	heap->Heap[s] = temp;
	s--;
}

void buildHeap(Heap* heap) {
	for (int i = (heap->n) / 2; i >= 1; i--) {
		downHeap(heap, i);
	}

}

void printHeap(Heap* heap) {
	for (int i = 1; i <= heap->n; i++) {
		printf(" %d", heap->Heap[i]);
	}
}

int main() {
	Heap heap;
	int n, k, s = 0;


	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		s += n;
	}
	init(&heap, s);

	for (int i = 1; i <= s; i++) {
		scanf("%d", &k);
		insertItem(&heap, i, k);
	}
	for (int i = 1; i <= s; i++) {
		root(&heap, s);
		buildHeap(&heap);
	}
	
	
	printHeap(&heap);

	return 0;
}
