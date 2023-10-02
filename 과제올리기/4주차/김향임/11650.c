#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
# include <time.h>

typedef struct element{
	int a;
	int b;
}Element;

int n;


void mergeSort(Element* A, Element * B);
void rMergeSort(Element* A, Element* B, int l, int r);
void merge(Element* A, Element* B, int l, int m, int r);
void swap(int* a, int* b);

int main() {

	scanf("%d", &n);

	Element* A = (struct element*)malloc(sizeof(struct element) * n);
	Element* B = (struct element*)malloc(sizeof(struct element) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i].a); 
		scanf("%d", &A[i].b);
	}

	mergeSort(A,B);
	
	for (int i = 0; i < n - 1; i++) {
		if (A[i].a == A[i+1].a) {
			if (A[i].b > A[i+1].b) {
				swap(&(A[i].a), &(A[i+1].a));
				swap(&(A[i].b), &(A[i + 1].b));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i].a);
		printf("%d\n", A[i].b);
	}

}


void mergeSort(Element* A, Element* B) {
	rMergeSort(A,B, 0, n-1);

	return;
}

void rMergeSort(Element* A, Element* B, int l, int r) {

	if (l < r) {
		int m = (l + r) / 2;
		rMergeSort(A,B, l, m);
		rMergeSort(A,B, m + 1, r);
		merge(A,B, l, m, r);
	}

	return;
}

void merge(Element* A, Element* B, int l, int m, int r) {

	printf("n=%d", n);

	int i = 0;
	int k = 0;
	int j = m + 1;

	while (i <= m && j <= r) {
		if (A[i].a <= A[j].a) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}

	while (i <= m) {
		B[k++] = A[i++];
	}

	while (j <= r) {
		B[k++] = A[j++];
	}

	for (int k = l; k <= r; k++) {
		A[k] = B[k];
	}

}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
