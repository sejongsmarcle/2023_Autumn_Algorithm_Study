#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <math.h>
#define SIZE 10001

#pragma warning (disable:4996)

typedef struct HashTable {
	int* A;
	int N;
}HashTable;

HashTable H;

void insert(int key);
void search(int key);
int getNextBucket(int n, int k);
int getMaxPrime(int input);

int main(void)
{
	//해시테이블 세팅
	scanf("%d", &H.N);

	H.A = (int*)calloc(SIZE, sizeof(int));

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
	int q = getMaxPrime(SIZE);
	int loc = SIZE + q - abs(k % q);

	if (loc > SIZE - 1)
		return loc - SIZE;

	else
		return loc;
}

void insert(int key) {
	int n = key % SIZE;
	if (n < 0) {
		n = n * ( - 1);
	}

	while (H.A[n] != 0) {
		n = getNextBucket(n, key);
	}

	H.A[n] = key;
}

void search(int key) {
	int n = key % SIZE;
	if (n < 0) {
		n = n * (-1);
	}
	int i = 0;

	while (i < SIZE) {
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

