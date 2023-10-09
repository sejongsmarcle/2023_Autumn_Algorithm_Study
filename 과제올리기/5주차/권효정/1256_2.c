#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

char result[201]; //���ڿ� result ����

long long binomialCoeff(int n, int k) { // ���� ����� ����ϴ� �Լ�
    if (k == 0 || k == n) //k�� 0�̰ų� n�� ������
    {
        return 1; //1�� return�Ѵ�
    }
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void find(int N, int M, long long K) { // K��° ���ڿ��� ã�� �Լ�
    int index = 0;
    if (K > binomialCoeff(N + M, N)) {
        printf("-1"); // K�� ������ ���ڿ��� ������ ũ�� -1 ���
        return;
    }

    while (N > 0 && M > 0) { //N�� M�� ��� 0���� Ŭ ��
        long long combination = binomialCoeff(N + M - 1, N - 1);

        if (K <= combination) {
            result[index++] = 'a'; //���ڿ��� a ����
            N--; //N�� 1 ����
        }
        else {
            result[index++] = 'z'; //���ڿ��� z ����
            M--; //M�� 1 ����
            K -= combination; //K�� (K - combination) �� ����
        }
    }

    while (N > 0) { //N�� 0���� Ŭ ��
        result[index++] = 'a'; //���ڿ��� a ����
        N--; //N�� 1 ����
    }

    while (M > 0) { //M�� 0���� Ŭ ��
        result[index++] = 'z'; //���ڿ��� z ����
        M--; //M�� 1 ����
    }

    result[index] = '\0'; //NULL�� ����
    printf("%s\n", result); //���ڿ� ���
}

int main() {
    int N, M;
    long long K;

    scanf("%d %d %lld", &N, &M, &K);

    find(N, M, K);

    return 0;
}
