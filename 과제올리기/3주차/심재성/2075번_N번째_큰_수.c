#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int Heap[1500]; 
int heapSize = 0;

void upHeap(int idx) {
	int tmp;
	int Parent = idx / 2;
	if (idx == 1 || Heap[Parent] <= Heap[idx]) return;
	tmp = Heap[Parent];
	Heap[Parent] = Heap[idx];
	Heap[idx] = tmp;
	upHeap(Parent);
}

void downHeap(int idx) { 
	int Leftchild_idx = 2 * idx, Rightchild_idx = 2 * idx + 1;
	int smaller_idx, tmp;
	if (Leftchild_idx > heapSize) return;
	smaller_idx = Leftchild_idx;
	if (Rightchild_idx <= heapSize) {
		if (Heap[smaller_idx] > Heap[Rightchild_idx]) smaller_idx = Rightchild_idx;
	}
	if (Heap[smaller_idx] < Heap[idx]) {
		tmp = Heap[smaller_idx];
		Heap[smaller_idx] = Heap[idx];
		Heap[idx] = tmp;
		downHeap(smaller_idx);
	}
}

void insert(int key) { 
	heapSize++;
	Heap[heapSize] = key;
	upHeap(heapSize);
}

int removeMin() {
	int root = Heap[1];
	Heap[1] = Heap[heapSize--];
	downHeap(1);
	return root;
}

int main() {
	int N;
	scanf("%d", &N);

	int key;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &key);
			insert(key);
			if (heapSize > N)
				removeMin();
		}
	}

	printf("%d\n", removeMin()); 

	return 0;
}
