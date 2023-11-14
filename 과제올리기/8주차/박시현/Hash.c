#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <math.h>

#pragma warning (disable:4996)

typedef struct HashTable {
	int* A;
	int N;
}HashTable;

HashTable H;

void insert(int key);
void search(int key);
void print();
int getNextBucket(int,int);
int getMaxPrime(int input);

int main(void)
{
	//해시테이블 세팅
	scanf("%d", &H.N);

	H.A = (int*)calloc(H.N, sizeof(int));

	//입력 
	int key;

	for (int i = 0; i < H.N; i++) {
		scanf("%d", &key);
		insert(key);
	}

	//해시테이블 탐색
	int M;
	int k;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &k);
		search(k);
	}

	free(H.A);
}

/* Get max prime number less than input integer. */
int getMaxPrime(int input) {
	int prime = 2;
	int num = 3;
	while (1) {
		int max = (int)sqrt(num);
		for (int i = 2; i <= max; i++) {
			if (num % i == 0) break;
			if (i == max) prime = num;
		}
		num++;
		if (num > input) break;
	}
	return prime;
}
int getNextBucket(int n, int k) {
	int q = getMaxPrime(H.N);
	int loc = n + q - (k % q);

	if (loc > H.N - 1)
		return loc-H.N;

	else
		return loc;
}

void insert(int key) {
	int n = key%H.N;

	while (H.A[n] != 0) {
		n=getNextBucket(n,key);
	}

	H.A[n] = key;
}

void search(int key) {
	int n = key % H.N;
	int i = 0;

	while (i<H.N) {
		n = getNextBucket(n, key);

		if (H.A[n] == key) {
			printf("1\n"); // 주소와 키
			return;
		}
		else if (H.A[n] == 0) {
			printf("0\n"); // 주소와 키
			return;
		}

		else
			i++;
	}
	printf("0\n"); // 주소와 키
}

void print() {
	for (int i = 0; i < H.N; i++)
		printf(" %d", H.A[i]);

	printf("\n");
}

