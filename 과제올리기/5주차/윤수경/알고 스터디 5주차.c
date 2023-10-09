#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#pragma warning (disable:4996)




// 문자열을 저장할 배열
char** result;
int resultCount = 0;

// 재귀 함수를 사용하여 모든 문자열 생성
void generateStrings(char* currentString, int aCount, int zCount, int length) {
    if (aCount == 0 && zCount == 0) {
        // 문자열 생성이 완료되면 배열에 저장
        result[resultCount] = strdup(currentString);
        resultCount++;
        return;
    }

    if (aCount > 0) {
        currentString[length] = 'a';
        generateStrings(currentString, aCount - 1, zCount, length + 1);
    }

    if (zCount > 0) {
        currentString[length] = 'z';
        generateStrings(currentString, aCount, zCount - 1, length + 1);
    }
}

int P(int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= i;
    }
    return sum;
}
int main() {
    int n, m, k; 
    scanf("%d %d %d", &n, &m, &k);

    // 가능한 문자열의 총 수 계산
    int np = P(n);
    int mp = P(m);
    int nmp = P(n + m);
    int totalStrings;
  
    totalStrings = nmp / (np * mp);
    if (k > totalStrings) {
        printf("-1");
        return 0;
    }
    
    else {
        // 결과 배열 할당
        result = (char**)malloc(totalStrings * sizeof(char*));

        char* currentString = (char*)malloc((n + m + 1) * sizeof(char));
        currentString[n + m] = '\0'; // NULL 문자 추가

        // 문자열 생성 시작
        generateStrings(currentString, n, m, 0);

        //generateStrings(currentString, 3, 2, 0);
        //a generateStrings(currentString, 2, 2, 1);
        //aa generateStrings(currentString, 1, 2, 2);
        //aaa generateStrings(currentString, 0, 2, 3);
        //aaaz generateStrings(currentString, 0, 1, 4);
        //aaazz generateStrings(currentString, 0, 0, 5);
        //result[0]=aaazz


        printf("%s\n", result[k - 1]);


        free(result);
        free(currentString);

        return 0;
    }
}
