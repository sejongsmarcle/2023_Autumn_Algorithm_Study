#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int matrix[100001][2];  
int pointed[100001] = { 0, };

int main() {
    int n;
    int T;
    scanf("%d", &T);
    int count = 0;

    while (T-->0) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &matrix[i][0]);
            pointed[matrix[i][0]] = 1;
        }


        for (int i = 1; i <= n; i++) {
            if (pointed[i]==0) {  
                int current = i;
                while (matrix[current][1] == 0) {  
                    matrix[current][1] = 1;  
                    current = matrix[current][0];  
                }

                while (matrix[current][1] == 1) {  
                    matrix[current][1] = 2;  
                    current = matrix[current][0];
                }
                current = i;
                while (matrix[current][1] == 1) {
                    matrix[current][1] = -1;
                    current = matrix[current][0];
                }
            }
        }
        count = 0;
        for (int i = 1; i <= n; i++) {
            if (matrix[i][1] == -1) {
                count++;
            }
            pointed[i] = matrix[i][1] = 0;
        }
        printf("%d\n", count);
    }
    return 0;
}

/*

2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8

*/
                    
                   
