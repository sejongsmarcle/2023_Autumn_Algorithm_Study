#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int N;
int M;
typedef struct node {
	int key;//값
	int index;
	int s;
}node;

void QuickSort(int* arr, int L, int R, int n) {
	int l = L;
	int r = R;
	int m = (l + r) / 2;
	int tmp;
	int pivot = arr[m];
	while (l < r) {
		while (arr[l] < pivot) l++;
		while (arr[r] > pivot)r--;

		if (l <= r) {
			if (l != r) {
				tmp = arr[l];
				arr[l] = arr[r];
				arr[r] = tmp;
			}
			l++; r--;
		}
	}
	if (L < l)
		QuickSort(arr, L, r, n);
	if (l < R)
		QuickSort(arr, l, R, n);
}

void QuickSort_node_index(node* arr, int L, int R, int n) {
	int l = L;
	int r = R;
	int m = (l + r) / 2;
	node tmp;
	node pivot = arr[m];
	while (l < r) {
		while (arr[l].index < pivot.index) l++;
		while (arr[r].index > pivot.index)r--;

		if (l <= r) { /*--재확인 하기--*/
			if (l != r) {
				tmp = arr[l];
				arr[l] = arr[r];
				arr[r] = tmp;
			}
			l++; r--;

		}
	}
	if (L < l)
		QuickSort_node_index(arr, L, r, n);
	if (l < R)
		QuickSort_node_index(arr, l, R, n);
}

void QuickSort_node(node* arr, int L, int R, int n) {
	int l = L;
	int r = R;
	int m = (l + r) / 2;
	node tmp;
	node pivot = arr[m];
	while (l < r) {
		while (arr[l].key < pivot.key) l++;
		while (arr[r].key > pivot.key)r--;

		if (l <= r) { /*--재확인 하기--*/
			if (l != r) {
				tmp = arr[l];
				arr[l] = arr[r];
				arr[r] = tmp;
			}
			l++; r--;

		}
	}
	if (L < l)
		QuickSort_node(arr, L, r, n);
	if (l < R)
		QuickSort_node(arr, l, R, n);
}

void search(int* arr, node* arr_s) {
	int a = 0;//arr_s
	int b = 0;//arr

	while (b < N && a < M) {
		if (arr_s[a].key == arr[b]) {
			arr_s[a].s = 1;
			a++;
		}
		else if (arr_s[a].key < arr[b]) {
			arr_s[a].s = 0;
			a++;
		}
		else if (arr_s[a].key > arr[b])b++;
	}
	if (a < M - 1) {
		for (; a < M; a++) {
			arr_s[a].s = 0;
		}
	}
}

int main() {
	int i;
	int* arr;
	node* arr_s = NULL;

	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &M);
	arr_s = (node*)malloc(sizeof(node) * M);

	for (i = 0; i < M; i++) {
		scanf("%d", &arr_s[i].key);
		arr_s[i].index = i;
	}


	QuickSort(arr, 0, N - 1, N);
	QuickSort_node(arr_s, 0, M - 1, M);


	search(arr, arr_s);

	QuickSort_node_index(arr_s, 0, M - 1, M);


	for (i = 0; i < M; i++) {
		printf("%d\n", arr_s[i].s);
	}

	return 0;
}