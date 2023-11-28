#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int matrix[100001][2]; 

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            matrix[i][0] = 0; 
            matrix[i][1] = 0;  
        }

      
        for (int i = 1; i <= n; i++) {
            int dest;
            scanf("%d", &dest);
            matrix[i][0] = dest;
        }

        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (!matrix[i][1]) { 
                int current = i;
                while (!matrix[current][1]) {
                    matrix[current][1] = 1; 
                    current = matrix[current][0]; 
                }

                int cycleStart = current;
                int cycleCount = 1;

                while (matrix[current][1] == 1) { 
                    matrix[current][1] = 2; 

                    
                    int nextStudent = matrix[current][0];
                    if (current != nextStudent) {
                        count++;  
                    }

                    current = nextStudent;  

                    if (current == cycleStart) {
                        break; 
                    }
                    cycleCount++;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
