#pragma warning(disable:4996)
#include <stdio.h>;
#include <stdlib.h>

int binary_search(int arr[], int key, int size);
int cmp(const void *a, const void *b);//qsort를 라이브러리에서 불러오기 위한 비교함수 설정



int main() {
	int N, M;
	int *arr_N;
	int *arr_M;

	scanf("%d", &N);
	arr_N = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) scanf("%d", &arr_N[i]);
	
	scanf("%d", &M);
	arr_M = (int *)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) scanf("%d", &arr_M[i]);

	qsort(arr_N, N, sizeof(int), cmp);

	for (int i = 0; i < M; i++) printf("%d\n", binary_search(arr_N, arr_M[i], N));

	return 0;

}

int binary_search(int arr[], int key, int size) {
	int front = 0, rear = size - 1, pivot;

	while (1) {
		pivot = (front + rear) / 2;
		if (arr[pivot] == key) return 1;
		if (arr[front] == key) return 1;
		if (arr[rear] == key) return 1;

		if (arr[pivot] < key) front = pivot + 1;
		else rear = pivot - 1;

		if (front >= rear) return 0;


	}

}
int cmp(const void *a, const void *b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

