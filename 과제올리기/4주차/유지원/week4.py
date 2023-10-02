import sys

N = int(sys.stdin.readline())
coor = []

for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())
    coor.append([x, y])

coor.sort()
for c in coor:
    print(c[0], c[1])
