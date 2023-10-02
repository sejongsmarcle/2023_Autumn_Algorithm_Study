#include <stdio.h>
#include <stdlib.h>
#pragma warninig(disable:4996)

typedef struct Point {
    int x;
    int y;
} Point;

int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;

    if (pointA->x < pointB->x || (pointA->x == pointB->x && pointA->y < pointB->y)) {
        return -1;
    } else {
        return 1;
    }
}

void inPlaceQuickSort(Point arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int k = (l + r) / 2;

    int a, b;
    a = b = inPlacePartition(arr, l, r, k);

    inPlaceQuickSort(arr, l, a - 1);
    inPlaceQuickSort(arr, b + 1, r);
}

int inPlacePartition(Point arr[], int l, int r, int k) {
    Point p = arr[k];
    arr[k] = arr[r];
    arr[r] = p;

    int i = l;
    int j = r - 1;

    while (1) {
        while (i <= j && compare(&arr[i], &p) <= 0) {
            i++;
        }
        while (i <= j && compare(&arr[j], &p) >= 0) {
            j--;
        }
        if (i < j) {
            Point temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            break;
        }
    }
    Point temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i;
}

int main() {
    int N;
    scanf("%d", &N);

    Point *points = (Point *)malloc(N * sizeof(Point));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    inPlaceQuickSort(points, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);
    return 0;
}
