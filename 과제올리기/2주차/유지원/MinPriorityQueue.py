"""
### 우선순위 큐 ADT ###
# Object
    : 키를 가진 원소 집합
# Operation
    1. is_empty() -> Boolean
        : 큐가 비어있으면 True, 아니면 False 반환
    2. push(item)
        : 큐에 원소 item 삽입
    3. pop() -> element
        : 큐에서 키 값이 가장 작은 요소를 삭제하며 반환
    4. min() -> element
        : 큐에서 키 값이 가장 작은 요소를 반환
"""
'''
from heapq import heappush, heappop


class Element:

    def __init__(self, key, string):
        self.key = key
        self.data = string


class MinPriorityQueue:

    def __init__(self):
        self.heap = []

    def is_empty(self):
        if not self.heap:
            return True
        return False

    def push(self, item):
        heappush(self.heap, (item.key, item.data))

    def pop(self):
        return heappop(self.heap)

    def min(self):
        return self.heap[0]

'''


def is_empty(self):
    if not self.heap:
        return True
    return False


import sys
import heapq
import copy

T = int(input())

for _ in range(T):
    heap = []

    M = int(input())
    nums = []
    for _ in range(M // 10 + 1):
        nums += list(map(int, input().split()))

    print((M + 1) // 2)
    for m in range(M):  # m = 0~8

        heapq.heappush(heap, nums[m])
        if (m + 1) % 2 == 1:  # m+1 = 1, 3, 5
            temp = copy.deepcopy(heap)

            for _ in range((m + 2) // 2):  # m+2 = 2, 4, 6
                mid = heapq.heappop(temp)

            print(mid, end=' ')
            if (m != 0 and m % 9 == 0) or m == M-1:
                print()
