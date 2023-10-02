#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//좌표-> coordinate라는 구조체를 설정해준다. x좌표, y좌표
typedef struct {
	int x;
	int y;
} coordinate;

// 그전에 공부했던 비교함수를 배열에서 int형 변환이 아닌 설정해둔 구조체 coordinate형으로 비교하고 변환해준다.
int compare(const void *a, const void *b) {
	coordinate *p1 = (coordinate *)a;
	coordinate *p2 = (coordinate *)b;

	//x좌표가 다르면 x로 정렬
	if (p1->x != p2->x) { 
		return p1->x - p2->x;
	}

	//x좌표가 같으면 y로 정렬
	return p1->y - p2->y;
}

int main() {
	int N;
	scanf("%d", &N);

	coordinate *points = (coordinate *)malloc(sizeof(coordinate) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	// 퀵 정렬을 사용하여 좌표 정렬
	qsort(points, N, sizeof(coordinate), compare);


	for (int i = 0; i < N; i++) {
		printf("%d %d\n", points[i].x, points[i].y);
	}

	free(points);

	return 0;
}
