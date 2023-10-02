#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

//좌표
typedef struct coordinate {
    int num;
    int* X;
    int* Y;
}coordinate;

//좌표 구조체
void init(coordinate*,int);

//합병정렬
int partition(int, int);
void merge(coordinate*, int, int, int);
void merge_sort(coordinate*, int, int);

int main(void)
{
    int N;
    coordinate C;

    scanf("%d", &N);

    init(&C,N);

    for (int i = 0; i < N; i++)
        scanf("%d %d",&C.X[i], &C.Y[i]);

    merge_sort(&C, 0, N-1);

    for (int i = 0; i < N; i++)
        printf("%d %d\n",C.X[i],C.Y[i]);

    free(C.X);
    free(C.Y);

}

void init(coordinate* C,int N) {
    C->num =N;
    C->X = (int*)malloc(sizeof(int) * N);
    C->Y = (int*)malloc(sizeof(int) * N);

}

int partition(int l, int r) {
    return (l + r) / 2;
}

void merge(coordinate* C, int l, int r, int m) {
    /**/
    int n = C->num;

    int* A = (int*)malloc(sizeof(int) * n);
    int* B=(int*)malloc(sizeof(int)*n);

    int i = l;
    int j = m + 1;
    int k = l;


    while ((i <= m) && (j <= r)) {
        if (C->X[i] < C->X[j]) {
            A[k] = C->X[i];
            B[k++] = C->Y[i++];

        }
       
        else if(C->X[i] > C->X[j]){
            A[k] = C->X[j];
            B[k++] = C->Y[j++];
        }

        else {
            if (C->Y[i] < C->Y[j]) {
                A[k] = C->X[i];
                B[k++] = C->Y[i++];
            }
            else {
                A[k] = C->X[j];
                B[k++] = C->Y[j++];
            }

        }
    }

    while (i <= m) {
        A[k] = C->X[i];
        B[k++] = C->Y[i++];
    }

    while (j <= r) {
        A[k] = C->X[j];
        B[k++] = C->Y[j++];
    }

    for (i = l; i <= r; i++) {
        C->X[i]= A[i] ;
        C->Y[i] = B[i];
    }

    free(A);
    free(B);
}

void merge_sort(coordinate* C, int l, int r) {

    if (l < r) {
        //분할
        int m = partition(l, r);

        //재귀
        merge_sort(C, l, m);
        merge_sort(C, m + 1, r);

        //합병
        merge(C, l, r, m);
    }

    else
        return;
}
