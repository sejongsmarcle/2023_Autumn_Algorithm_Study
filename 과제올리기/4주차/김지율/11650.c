#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} coor;

coor sort[100001];
coor B[100001];

void rMergeSort(coor* A, int l, int r);
void merge(coor* A, int l, int m, int r);
void mergesort(coor* arr, int first, int last);
void Merge(coor* arr, int first, int mid, int last);


int main() {

    int N, i;

    scanf("%d", &N);

    coor* A = (coor*)malloc((N + 1) * sizeof(coor));

    for (i = 0; i < N; i++)
        scanf("%d %d", &A[i].x, &A[i].y);

    rMergeSort(A, 0, N - 1);
    //mergesort(A, 0, N - 1);

    for (i = 0; i < N; i++)
        printf("%d %d\n", A[i].x, A[i].y);

    return 0;
}

void rMergeSort(coor* A, int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        rMergeSort(A, l, m);
        rMergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

//void Merge(coor* arr, int first, int mid, int last)
//{
//    int i, j, k;
//    i = first;
//    j = mid + 1;
//    k = first;
//
//    while (i <= mid && j <= last) {
//        if (arr[i].x < arr[j].x)
//            sort[k++] = arr[i++];
//        else if (arr[i].x > arr[j].x)
//            sort[k++] = arr[j++];
//        else {
//            if (arr[i].y < arr[j].y)
//                sort[k++] = arr[i++];
//            else if (arr[i].y > arr[j].y)
//                sort[k++] = arr[j++];
//        }
//    }
//
//    if (i <= mid) {
//        while (i <= mid)
//            sort[k++] = arr[i++];
//    }
//    else {
//        while (j <= last)
//            sort[k++] = arr[j++];
//    }
//    for (k = first; k <= last; k++)
//        arr[k] = sort[k];
//}

void merge(coor* A, int l, int m, int r) {

    int i = l, k = l, j = m + 1;

    while (i <= m && j <= r) {
        if (A[i].x < A[j].x)
            B[k++] = A[i++];
        else if (A[i].x > A[j].x)
            B[k++] = A[j++];
        else if (A[i].x == A[j].x) {
            if (A[i].y < A[j].y)
                B[k++] = A[i++];
            else if (A[i].y > A[j].y)
                B[k++] = A[j++];
        }
    }

    while (i <= m)
        B[k++] = A[i++];

    while (j <= r)
        B[k++] = A[j++];

    for (k = l; k <= r; k++)
        A[k] = B[k];

}