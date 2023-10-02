#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** arr;
int n;//x값의 개수
int n_copy;
int id_x = 0, id_y = 0;
void downHeap_x(int id);
void downHeap_y(int id);
void rebuildHeap(int id);
void inPlaceHeapSort();
void Print();

int main() {
	int i;
	int x, y;
	scanf("%d", &n);
	n_copy = n;

	arr = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i <= n; i++) {     //쓰읍 오래걸리려나
		arr[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		//원래 arr[i]에n개의 배열을 할당 했는데 버리는 공간이 많은것 같아 수정, 
	}

	inPlaceHeapSort();

	Print();

	return 0;
}

void inPlaceHeapSort() {

	int j;
	rebuildHeap(1);
	int stm_x = 0;
	int stm_y = 0;

	for (j = n; j >= 1; j--) {
		stm_x = arr[j][0];
		stm_y = arr[j][1];
		arr[j][0] = arr[1][0];
		arr[j][1] = arr[1][1];
		arr[1][0] = stm_x;
		arr[1][1] = stm_y;
		n--;
		downHeap_x(1);
	}
}

void rebuildHeap(int id) {

	if (id > n) return;
	rebuildHeap(2 * id);
	rebuildHeap(2 * id + 1);
	downHeap_x(id);

}

void downHeap_x(int id) {
	int left = id * 2;
	int right = id * 2 + 1;

	int B;
	int stm_x, stm_y;

	if (left > n) return;
	B = left;
	if (right <= n) {
		if (arr[B][0] < arr[right][0])
			B = right;
	}
	if (arr[B][0] > arr[id][0]) {
		stm_x = arr[id][0];
		stm_y = arr[id][1];
		arr[id][0] = arr[B][0];
		arr[id][1] = arr[B][1];
		arr[B][0] = stm_x;
		arr[B][1] = stm_y;
		downHeap_x(B);
	}
	if (arr[id][0] != arr[B][0]) return;
	if (arr[id][1] < arr[B][1]) {
		stm_x = arr[id][0];
		stm_y = arr[id][1];
		arr[id][0] = arr[B][0];
		arr[id][1] = arr[B][1];
		arr[B][0] = stm_x;
		arr[B][1] = stm_y;
		downHeap_x(id);
	}
}


void Print() {
	int i;
	for (i = 1; i <= n_copy; i++) {
		printf("%d %d\n", arr[i][0], arr[i][1]);
	}
}