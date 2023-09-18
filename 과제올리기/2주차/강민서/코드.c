#include <stdio.h>
#include <stdlib.h>

// 최대 힙 (Max Heap) 구조체 정의
typedef struct {
    int* data;     // 데이터 배열
    int capacity;  // 용량
    int size;      // 현재 크기
} MaxHeap;

// 최대 힙 초기화 함수
MaxHeap* initializeMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// 최대 힙에 원소 추가
void insertMaxHeap(MaxHeap* heap, int value) {
    if (heap->size < heap->capacity) {
        int index = heap->size++;
        heap->data[index] = value;

        // 최대 힙 속성 유지
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap->data[index] > heap->data[parent]) {
                // 부모와 자식 노드 교환
                int temp = heap->data[index];
                heap->data[index] = heap->data[parent];
                heap->data[parent] = temp;
                index = parent;
            } else {
                break; // 최대 힙 속성 만족
            }
        }
    }
}

// 최대 힙에서 최댓값 추출
int extractMax(MaxHeap* heap) {
    if (heap->size > 0) {
        int maxValue = heap->data[0];
        heap->data[0] = heap->data[--heap->size];

        // 최대 힙 속성 복구
        int index = 0;
        while (1) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < heap->size && heap->data[leftChild] > heap->data[largest]) {
                largest = leftChild;
            }
            if (rightChild < heap->size && heap->data[rightChild] > heap->data[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                // 현재 노드와 최대 자식 노드 교환
                int temp = heap->data[index];
                heap->data[index] = heap->data[largest];
                heap->data[largest] = temp;
                index = largest;
            } else {
                break; // 최대 힙 속성 만족
            }
        }

        return maxValue;
    } else {
        // 큐가 비어있을 경우
        return -1; // 예외 처리
    }
}

// 최소 힙 (Min Heap) 구조체 정의
typedef struct {
    int* data;     // 데이터 배열
    int capacity;  // 용량
    int size;      // 현재 크기
} MinHeap;

// 최소 힙 초기화 함수
MinHeap* initializeMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// 최소 힙에 원소 추가
void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size < heap->capacity) {
        int index = heap->size++;
        heap->data[index] = value;

        // 최소 힙 속성 유지
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap->data[index] < heap->data[parent]) {
                // 부모와 자식 노드 교환
                int temp = heap->data[index];
                heap->data[index] = heap->data[parent];
                heap->data[parent] = temp;
                index = parent;
            } else {
                break; // 최소 힙 속성 만족
            }
        }
    }
}

// 최소 힙에서 최솟값 추출
int extractMin(MinHeap* heap) {
    if (heap->size > 0) {
        int minValue = heap->data[0];
        heap->data[0] = heap->data[--heap->size];

        // 최소 힙 속성 복구
        int index = 0;
        while (1) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < heap->size && heap->data[leftChild] < heap->data[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < heap->size && heap->data[rightChild] < heap->data[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                // 현재 노드와 최소 자식 노드 교환
                int temp = heap->data[index];
                heap->data[index] = heap->data[smallest];
                heap->data[smallest] = temp;
                index = smallest;
            } else {
                break; // 최소 힙 속성 만족
            }
        }

        return minValue;
    } else {
        // 큐가 비어있을 경우
        return -1; // 예외 처리
    }
}

int main(void) {
    int T; // 테스트 케이스 수
    scanf("%d", &T);

    while (T--) {
        int M; // 수열의 크기
        scanf("%d", &M);

        MaxHeap* maxHeap = initializeMaxHeap(M);
        MinHeap* minHeap = initializeMinHeap(M);

        for (int i = 1; i <= M; i++) {
            int value;
            scanf("%d", &value);
            if (i % 2 == 1) {
                insertMaxHeap(maxHeap, value);
                insertMinHeap(minHeap, extractMax(maxHeap)); // 최대 힙에서 최댓값을 추출하고 최소 힙에 삽입
                printf("%d ", minHeap->data[0]); // 중앙값 출력
            }
        }

        printf("\n");

        free(maxHeap->data);
        free(maxHeap);
        free(minHeap->data);
        free(minHeap);
    }

    return 0;
}
