from math import factorial
import sys

def NcM(n, m):
    return factorial(n+m) / (factorial(n) * factorial(m))



n, m, k = map(int, sys.stdin.readline().split())

if NcM(n,m) < k:
    result = -1

else:
    k -= 1
    result = ""

    while True:
        if n == 0 or m == 0:
            break

        caseNum = NcM(n-1, m)

        if k < caseNum:
            result += "a"
            n -= 1
        else:
            result += "z"
            m -= 1
            k -= caseNum

    result += "z" * m + "a" * n

print(result)
