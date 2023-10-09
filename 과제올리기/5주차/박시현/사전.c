#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

void makeWord(char*,int,int, int,int,int*);

int main(void)
{	
    //======================================정보 입력===========================================
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

    char* word = (char*)malloc(sizeof(char) * (N + M + 1));

    int cnt = 0;
    //===================================사전 단어 개수======================================
    unsigned long long size=1;

    if (N == 0||M==0)
        size = 1;
 
    else {
        for (int i = N + M; i >= 1; i--)
            size *= i;

        for (int i = N ; i >= 1; i--)
            size /= i;

        for (int i = M; i >= 1; i--)
            size /= i;

    }

    //=================================사전 단어 개수 판별==================================
    if (size < K) {
        printf("-1\n");
    }
    
    else {
        word[N + M] = '\0';
        makeWord(word, 0, N, M,K,&cnt);
    }
    /*char** Dict;

	char* word = (char*)malloc(sizeof(char) * (N + M+1));

    makeWord(word,0,N, M);

	printf("%s",*Dict[K]);*/
}

void makeWord(char* word,int i, int N, int M,int K,int *cnt) {

    if (N <= 0) {
        while (M > 0) {
            word[i++] = 'z';
            M--;
        }
    }

    else if (M <= 0) {
        while (N > 0) {
            word[i] = 'a';
            i++;
            N--;
        }
    }

    else if ((N <= 0) && (M <= 0)) {
    }

    else {
        word[i] = 'a';
        makeWord(word,i + 1,N-1,M,K,cnt);

        word[i] = 'z';
        makeWord(word,i + 1, N, M-1,K,cnt);

    }

    if ((N <= 0) && (M <= 0)) {
        (*cnt)++;
        if (*cnt == K)
            printf("%s\n", word);
    }

}

