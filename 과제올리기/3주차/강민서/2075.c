#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//전역변수
int* H = NULL;
int size = 0;

//힙 정렬
void downHeap(int i) {
    int bigger;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (size < left) { return; } //자식이 없는 상태

    bigger = left;

    if (right <= size) { 
        if (H[right] > H[bigger]) { //더 크면 오른쪽 자식 선택
            bigger = right;
        }
    }

    //선택한 자식과 현재 노드 비교
    if (H[bigger] <= H[i]) { return; } 
    //교환
    int tmp = H[i];
    H[i] = H[bigger];
    H[bigger] = tmp;

    downHeap(bigger);
}
//상향식 힙 (재귀)
int rBuildHeap(int i) {
    if (i > size) { return size; }

    rBuildHeap(i * 2);
    rBuildHeap(i * 2 + 1);

    downHeap(i);

    return size;
}
//최대값 제거, 반환 함수
int removeMax() {
    int key = H[1];
    H[1] = H[size--];
    downHeap(1);
    return key;
}

int main() {
    int N;
    scanf("%d", &N);
    size = N * N;

    H = (int*)malloc(sizeof(int) * (size+1));

    for (int i = 1; i < size+1; i++) {
        scanf("%d", &H[i]);
    }

    rBuildHeap(1);

    for (int i = 0; i < N - 1; i++) {
        removeMax(); //N-1번만 제거
    }
    printf("%d\n", removeMax()); //제거, 출력

    free(H);

    return 0;
}
