#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//��ǥ-> coordinate��� ����ü�� �������ش�. x��ǥ, y��ǥ
typedef struct {
	int x;
	int y;
} coordinate;

// ������ �����ߴ� ���Լ��� �迭���� int�� ��ȯ�� �ƴ� �����ص� ����ü coordinate������ ���ϰ� ��ȯ���ش�.
int compare(const void *a, const void *b) {
	coordinate *p1 = (coordinate *)a;
	coordinate *p2 = (coordinate *)b;

	//x��ǥ�� �ٸ��� x�� ����
	if (p1->x != p2->x) { 
		return p1->x - p2->x;
	}

	//x��ǥ�� ������ y�� ����
	return p1->y - p2->y;
}

int main() {
	int N;
	scanf("%d", &N);

	coordinate *points = (coordinate *)malloc(sizeof(coordinate) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	// �� ������ ����Ͽ� ��ǥ ����
	qsort(points, N, sizeof(coordinate), compare);


	for (int i = 0; i < N; i++) {
		printf("%d %d\n", points[i].x, points[i].y);
	}

	free(points);

	return 0;
}
