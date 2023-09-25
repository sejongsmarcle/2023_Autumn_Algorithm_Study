#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int n = 0;
int* H = NULL;

void printHeap() {
	for (int i = 1; i <= n; i++) { //첫번째부터 마지막 번째까지 힙의 원소를 출력
		printf("%d ", H[i]);
	}
	printf("\n");
}

void downHeap(int i) {
	//일차적으로 왼쪽 자식과 오른쪽 자식중에서 더 큰값을 찾는 과정
	int left = 2 * i;
	int right = 2 * i + 1; //배열에서 왼쪽과 오른쪽 노드 역할을 하는 인덱스 찾기
	if (left > n) //2i에 해당하는 인덱스가 마지막 번째 인덱스를 넘어서면 종료
		return;
	int child = left; //일단 일차적으로 왼쪽값을 더 크다고 가정한 뒤에
	if (right <= n)
		if (H[child] < H[right]) { //더 큰 값을 찾아서 자식(child)에 저장
			child = right;
		}

	//자식중에서 더 큰 값을 찾았으니, 그 값과 현재노드(부모노드)값을 비교
	if (H[child] <= H[i]) //최대힙에서 부모가 자식보다 값이 크거나 같으면 정상적으로 정렬된것, 종료함.
		return;
	//부모가 자식보다 값이 작으면 둘의 순서를 바꿔서 힙속성 복구
	int tmp = H[i];
	H[i] = H[child];
	H[child] = tmp;
	//이 과정을 계속해서 반복하여 맨 위의 루트노드부터 리프노드까지 정렬(부모의 값이 밑의 두 자식보다 항상 크도록)
	downHeap(child);
}

int rBuildHeap(int i) {
	if (i > n)
		return n;
	rBuildHeap(2 * i); //왼쪽 힙을 만듬.
	rBuildHeap(2 * i + 1); //오른쪽 힙을 만듬.
	//그것들을 차례대로 정렬시킴(전체 힙을 완성하기 전, 각각의 부분힙부터 하나하나씩 정렬 시작 - 이후 그 힙들에 루트노드를 붙이고 다시 정렬하는 방식을 반복)
	//가운데 원소, 즉 루트 원소들을 넣어주는 형태이기에 위에서부터 정렬해야 하므로 downheap사용
	downHeap(i);
	return n;
}

int removeMax() {
	int tmp = H[1];
	H[1] = H[n];
	n = n - 1;
	downHeap(1);
	return tmp;
}

int main() {
	scanf("%d", &n); //n을 입력받음

	int tmp = n; //n값 미리 저장해둠(전역변수라서 어쩔수 없음)
	n = n * n;

	H = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &H[i]); //상향식 힙을 만들기 전 기본 배열을 전부 입력받음
	}

	rBuildHeap(1); //상향식 힙생성(재귀문 이용방식)

	for (int i = 0; i < tmp - 1; i++) {
		removeMax();
	}
	printf("%d\n", removeMax());
	free(H);
	return 0;
}
