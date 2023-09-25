#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int* H, n, cnt = 0;

int removeMax() {
	int key = H[1];
	H[1] = H[n];
	n--;
	downHeap(1);
	return key;
}

int upHeap(int i) {
	int tmp;
	if (i == 1) {
		return;
	}
	int p = i / 2;
	if (H[i] <= H[p]) {
		return;
	}
	tmp = H[i];
	H[i] = H[p];
	H[p] = tmp;
	upHeap(p);
}

void printHeap() {
	//출력 확인용
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}printf("\n");
}

int downHeap(int i) {
	int l = 2 * i;
	int r = 2 * i + 1;
	int tmp;
	if (l > n) {
		return;
	}
	int big = l;

	if (H[r] > H[big] && n >= r) {
		big = r;
	}

	if (H[i] < H[big])
	{
		tmp = H[i];
		H[i] = H[big];
		H[big] = tmp;
	}
	else {
		return;
	}
	downHeap(big);
}

int main()
{
	int N;
	scanf("%d", &N);
	int f, b = N;
	n = N * N;

	H = (int*)malloc(sizeof(int) * n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
		cnt++;
		upHeap(i);
	}

	//printHeap();

	for (int i = 1; i <= b; i++) {
		f = removeMax();
		//printf("//%d %d %d %d\n", b, n, i, f);
		if (i == b) {
			printf("%d", f);
		}
	}
}
