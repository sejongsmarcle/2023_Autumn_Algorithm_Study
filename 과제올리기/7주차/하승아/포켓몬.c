#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int M;
int n;
typedef struct Node {
	int id;
	char key[21]; //포켓몬 이름의 최대길이는 20, 최소길이는 2
}Node;

void QuickSort(Node* arr_s, int left, int right) {
	int L = left, R = right;
//	int temp;
	Node pivot = arr_s[(left + right) / 2];
	Node tmp;

	while (L <= R) {
		while (strcmp(arr_s[L].key, pivot.key) <0)
			L++;
		while (strcmp(arr_s[R].key, pivot.key) > 0)
			R--;
		if (L <= R) { 
			if (L != R) { 
				strcpy(tmp.key,arr_s[L].key);
				tmp.id = arr_s[L].id;
				strcpy(arr_s[L].key,arr_s[R].key);
				arr_s[L].id = arr_s[R].id;
				strcpy(arr_s[R].key, tmp.key);
				arr_s[R].id = tmp.id;
			}
			L++; R--;

//			for (int i = 0; i < 10; i++) {
	//			printf("%s %d ", arr_s[i].key,arr_s[i].id);
	//		}
	//		printf("\n");
		}
	}
//	printf("\n");
	if (left < R)
		QuickSort(arr_s, left, R);
	if (L < right)
		QuickSort(arr_s, L, right);
}

void num_search(Node * arr, int k) {
	printf("%s\n", arr[k - 1].key);
}

void char_search(Node* arr_s, char* s, int l, int r) {
	int mid, left = 0, right = n - 1;
	while (right >= left) {
		mid = (left + right) / 2;
		if (strcmp(arr_s[mid].key, s) == 0) break;
		else if (strcmp(arr_s[mid].key, s) > 0) right = mid - 1;
		else left = mid + 1;
	}
	printf("%d\n", arr_s[mid].id);
}

int main() {
	scanf("%d %d", &n, &M);
	Node* arr = NULL;
	arr=(Node*)malloc(sizeof(Node) * n);
	Node* arr_s = NULL;
	arr_s = (Node*)malloc(sizeof(Node) * n);

	int i;
	char in[21];
	int k;

	for (i = 0; i < n; i++) {
	//	getchar();
		scanf("%s", arr[i].key);
		strcpy(arr_s[i].key, arr[i].key);
//		printf("          %s %d\n",arr_s[i].key, i + 1);
		arr_s[i].id = arr[i].id = i + 1;
	}

	//mergeSort(arr_s, 0, n - 1, arr_sub);
	QuickSort(arr_s, 0, n - 1);

//	for (i = 0; i < n; i++) {
//		printf("%s %d\n", arr_s[i].key, arr_s[i].id);
//	}

	for (i = 0; i < M; i++) {
		scanf("%s", in);
		if (in[0] >= '0' && in[0] <= '9') {
			k = atoi(in);
			num_search(arr, k);
		//	printf(" k= %d\n", k);
		}
		else {
			char_search(arr_s, in, 0, n-1);
		}
	}


	return 0;
}