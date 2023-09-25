#include<stdio.h>
#include<stdlib.h>

void downHeap(int id);
void rebuildHeap(int id);
int removeMax();

int *H=NULL;
int n=0;

int main() {
	int i;
	scanf("%d", &n);
	int cnt = n;
	n = n * n;
	H = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}

	rebuildHeap(1);
	for (i = 0; i < cnt-1; i++) {
		removeMax();
	}

	printf("%d", H[1]);

	return 0;
}

//--downheap은 위(루트)에서부터 아래로
void downHeap(int id) {
	//힙 내 id위치에 저장된 키를 크기에 맞는 위치로 하향 이동 
	//--가장 큰 키 값이 루트로 가도록..--
	int left = id * 2;
	int right = id * 2 + 1;

	int BigOne;
	int stm;

	if (left > n) return; //왼쪽에 아무런 노드도 없다면 종료
	BigOne = left;
	if (right <= n) { //오른쪽노드가 있다면 먼저 검사
		if (H[BigOne] < H[right]) //오른쪽 키가 왼쪽보다 크다면
			BigOne = right; //가장 큰 키를 향하는 인덱스변경
	}
	if (H[BigOne] > H[id]) { //만약 가장 큰 라스트 노드가 헤드보다 크다면
		stm = H[id];
		H[id] = H[BigOne];
		H[BigOne] = stm;
		downHeap(BigOne);//루트와 바꾼 자리부터 다시 크기순으로 정렬
	}
}

void rebuildHeap(int id) {
	if (id > n) return ; //알고리즘 설계 팁 1번
	rebuildHeap(2 * id);
	rebuildHeap(2 * id + 1);
	downHeap(id);
}

int removeMax() {
	//d 키삭제, 반환된 키 출력 -> 반환을 할 것인가/ 함수 내에서 출력 할 것인가

	int root;
	root = H[1];
	H[1] = H[n]; //루트 값 삭제, 마지막 노드를 위로 올리기.
	n--;
	downHeap(1); //정렬
	return root;
}