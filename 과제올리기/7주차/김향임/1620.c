#pragma warning(disable:4996)
#pragma warning(disable:4013)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char key[21];
    int num;
} node;

int compare(const void* a, const void* b) {
    return strcmp(((node*)a)->key, ((node*)b)->key);
}

int main() {
    node* root = NULL;
    node* nSorted = NULL;
    char k[21] = { 0 };
    char p[21] = { 0 };
    int n, m;
    node* r;

    scanf("%d %d", &n, &m);

    root = (node*)calloc(n+1, sizeof(node));
    nSorted = (node*)calloc(n + 1, sizeof(node));
    
    for (int i = 0; i < n; i++) {
        scanf("%s", root[i].key);
        root[i].num = i+1;
        nSorted[i] = root[i];
    }

    qsort(root, n, sizeof(node), compare);


   // printf("------------\n");
    
    for (int i = 0; i < m; i++) {
        scanf("%s", p);
        if (atoi(p) > 0) {
            int swit = atoi(p);
            printf("%s\n", nSorted[swit-1].key);
        }
        else {

            int left, right, mid;
            left = 0, right = n - 1;

            while (left <= right) {
                mid = (left + right) / 2;
                int compare_result = strcmp(root[mid].key, p);
                if (compare_result == 0) {
                    printf("%d\n", root[mid].num);
                    break;
                }
                else if (compare_result > 0) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
    }


    return 0;
}
