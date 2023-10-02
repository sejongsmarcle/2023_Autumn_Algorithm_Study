#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	int x;
	int y;
}XY;

void merge(XY xy[], int l, int m, int r); 
void rMergeSort(XY xy[], int l, int r);

void rMergeSort(XY xy[], int l, int r) {
	if (l >= r)
		return;
	int m = (l + r) / 2; //배열 분할을 이걸로 대체
	rMergeSort(xy, l, m); //각각 정렬
	rMergeSort(xy, m + 1, r);
	merge(xy, l, m, r); //합병
}

XY sorted[100000];//왜인지는 모르겠는데 이거 함수 안에 넣으면 오류남

void merge(XY xy[], int l, int m, int r) {

	int i = l, j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (xy[i].x < xy[j].x) {
			sorted[k++] = xy[i++];
		}
		else if (xy[i].x > xy[j].x) {
			sorted[k++] = xy[j++];
		}
		else {
			if (xy[i].y < xy[j].y) {
				sorted[k++] = xy[i++];
			}
			else if (xy[i].y > xy[j].y) {
				sorted[k++] = xy[j++];
			}
		}
	}

	if (i <= m) {
		while (i <= m) {
			sorted[k++] = xy[i++];
		}
	}
	if (j <= r) {
		while (j <= r) {
			sorted[k++] = xy[j++];
		}
	}
	for (int i = l; i <= r; i++){ 
		xy[i] = sorted[i];
	}
}

int main() {

	int n;
	XY xy[100000]; //구조체 배열 선언

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &xy[i].x, &xy[i].y);
	}

	rMergeSort(xy, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", xy[i].x, xy[i].y);
	}

	return 0;
}
