#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct {
    int x;
    int y;
} mer;

int N;
mer B[100000];

void merge(mer* A, int l, int m, int r)
{
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r) 
    {
        if (A[i].x < A[j].x) 
        {
            B[k++] = A[i++];
        }
        else if (A[i].x > A[j].x)
        {
            B[k++] = A[j++];
        }
        else 
        {
            if (A[i].y < A[j].y)
            {
                B[k++] = A[i++];
            }
            else if (A[i].y > A[j].y)
            {
                B[k++] = A[j++];
            }
        }
    }

    if (i <= m) 
    {
        while (i <= m)
        {
            B[k++] = A[i++];
        }
    }
    else 
    {
        while (j <= r)
        {
            B[k++] = A[j++];
        }
    }
    for (k = l; k <= r; k++)
    {
        A[k] = B[k];
    }
}

void merge_sort(mer* A, int l, int r) 
{
    int m;

    if (l < r) 
    {
        m = (l + r) / 2;
        merge_sort(A, l, m);
        merge_sort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main(void)
{
    scanf("%d", &N);

    mer* A = (mer*)malloc(sizeof(mer) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i].x, &A[i].y);
    }

    merge_sort(A, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", A[i].x, A[i].y);
    }
}