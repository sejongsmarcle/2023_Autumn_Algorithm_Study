#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void makeArray(int*, int);
void printArray(int*, int);
void printMedianNum(int);
void printMedian(int *, int);

int main() {
    int T, M;
    int* A = NULL;

    int i, j,k;
    int save;
    int cnt = 1;
    int Medianloc = 0;

    //테스트 케이스의 개수
    scanf("%d", &T);


    //테스트 케이스만큼 반복
    for (k = 0; k < T; k++) {
        scanf("%d", &M);

        //M 개의 정보를 저장하는 연결 리스트 생성
        A = (int*)malloc(sizeof(int) * M);
        makeArray(A, M);

        printMedianNum(M);
        
        //첫번째는 반드시 출력하게 됨.
        printf("%d ", A[0]);

        //제자리 삽입 정렬
        cnt = 1;
        for (i = 1; i <= M - 1; i++) {
            j = i - 1;
            save = A[i];

            while (j >= 0 && save < A[j]) { //추가될 아이 비교하기
                A[j + 1] = A[j];
                j--;
            }

            A[j + 1] = save;

            //중앙값 찾아주기
            if ((i + 1) % 2 != 0) {
                cnt++;
                Medianloc = (0 + i) / 2;
                printf("%d ", A[Medianloc]);
                if (cnt % 10 == 0)
                    printf("\n");
            }

        }
        printf("\n");



        free(A);
        
    }

    return 0;
}

void makeArray(int* A, int n) { //난수발생을 통해 초기화
    int i;
    int N;

    for (i = 0; i < n; i++) {
        scanf("%d", &N);
        A[i] = N;
    }
}


void printArray(int* A, int n) {  //정렬 결과 출력.
    for (int i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
}

void printMedianNum(int M) {
    int Medianloc = (1 + M) / 2;

    printf("%d\n", Medianloc);
}
