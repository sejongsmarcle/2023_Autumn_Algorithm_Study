import sys

def binary_search(dic, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if dic[mid][1] == target:
        return dic[mid][0]
    elif dic[mid][1] > target:
        return binary_search(dic, target, start, mid - 1)
    else:
        return binary_search(dic, target, mid + 1, end)

N, M = list(map(int, sys.stdin.readline().strip().split()))

pokemon = {}

for i in range(N):
    pokemon[str(i + 1)] = sys.stdin.readline().strip()

pokemon_list = sorted(pokemon.items(), key=lambda x: x[1])

for _ in range(M):
    target = sys.stdin.readline().strip()

    if target.isdigit():
        print(pokemon[target])
    else:
        print(binary_search(pokemon_list, target, 0, N - 1))
