#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#pragma warning (disable:4996)


#define MAX_SIZE 100000

typedef struct Point {
    int x, y;
} Point;

Point sorted[MAX_SIZE]; // sorted 배열을 Point 형태로 변경

void merge(Point list[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i].x < list[j].x || (list[i].x == list[j].x && list[i].y < list[j].y)) {
            sorted[k++] = list[i++];
        }
        else {
            sorted[k++] = list[j++];
        }
    }

    while (i <= mid) {
        sorted[k++] = list[i++];
    }
    while (j <= right) {
        sorted[k++] = list[j++];
    }

    // sorted 배열을 list 배열로 복사
    for (int l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

// 합병 정렬
void merge_sort(Point list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main() {
    int N;

    scanf("%d", &N);

    Point* points = (Point*)malloc(sizeof(Point) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    merge_sort(points, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);

    return 0;
}
