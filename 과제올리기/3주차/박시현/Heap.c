#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning (disable:4996)


//필요 데이터구조인 정수형 배열과 변수 선언
int*H=NULL;
int size=0; //힙의 크기

//필요한 함수 선언
void DownHeap(int);

//상향식 힙생성
void rBuildHeap(int);

int main() {
	int n;
	int i;

	//N에 대한 정보 입력 받기
	scanf("%d",&n);

	size = n * n;
	
	//배열 형성
	H = (int*)malloc(sizeof(int)*(size+1));

	//예외처리에 대한 조건문
	if (H == NULL) return -1;

	//키들 한꺼번에 입력받기 (이진트리 형식으로 H 구성)
	for (i = 1; i <= size; i++)
		scanf("%d",&H[i]);

	//상향식 힙 생성
	rBuildHeap(1);


	//힙정렬 - N번째 큰 수 출력
	int k; 

	for ( i = 0; i < n; i++) {
		//n번째 큰수
		k = H[1];

		//교환
		H[1] = H[size];

		//사이즈 줄이기
		size--;

		//힙순서 정렬
		DownHeap(1);
	}

	printf("%d\n",k);

	free(H);
	return 0;
}

//상향식 힙생성
void rBuildHeap(int i) {
	int left = 2 * i;
	int right = 2 * i + 1;

	if (i>size) //종료 조건 : 키가 없는 외부노드로 진입할 때
		return;

	rBuildHeap(left);
	rBuildHeap(right);

	DownHeap(i);
}

void DownHeap(int i) {
	//종료조건 1
	if (2 * i > size) //외부노드일 경우.
		return;

	//바꿔줄 자식 찾기
	int biggerIdx = i * 2;
	if (2*i+1<=size && H[biggerIdx] < H[biggerIdx + 1])
		biggerIdx++;

	//종료조건 2
	if (H[biggerIdx] <= H[i])
		return;

	//Swap
	int tmp = H[i];
	H[i] = H[biggerIdx];
	H[biggerIdx] = tmp;

	//재귀
	DownHeap(biggerIdx);
}
