import sys

N = int(sys.stdin.readline())
given = list(map(int, sys.stdin.readline().split()))
given_dict = {}
for key in given:
    given_dict[key] = ' '
M = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))

for num in numbers:
    if num in given_dict:
        print('1')
    else:
        print('0')
