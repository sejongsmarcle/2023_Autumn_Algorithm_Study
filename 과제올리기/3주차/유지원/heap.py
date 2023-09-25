from sys import stdin
from heapq import heappush, heappop

N = int(stdin.readline().rstrip())
heap = []

for _ in range(N):
    line = []
    line = list(map(int, stdin.readline().rstrip().split(' ')))
    for l in line:
        if len(heap) < N:
            heappush(heap, l)
        else:
            if heap[0] < l:
                heappop(heap)
                heappush(heap, l)

print(heap[0])
