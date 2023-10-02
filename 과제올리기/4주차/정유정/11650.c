#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

void merge(struct Point a[], struct Point b[], int left, int mid, int right) {
    int i = left, k = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (a[i].x < a[j].x)
            b[k++] = a[i++];
        else if (a[i].x == a[j].x && a[i].y < a[j].y)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= right)
        b[k++] = a[j++];
    for (k = left; k <= right; k++)
        a[k] = b[k];
}

void mergeSort(struct Point a[], struct Point b[], int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        mergeSort(a, b, left, mid);
        mergeSort(a, b, mid + 1, right);
        merge(a, b, left, mid, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    struct Point* a = (struct Point*)malloc(N * sizeof(struct Point));
    struct Point* b = (struct Point*)malloc(N * sizeof(struct Point));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    mergeSort(a, b, 0, N-1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", a[i].x, a[i].y);
    }

    free(a);
    free(b);

    return 0;
}