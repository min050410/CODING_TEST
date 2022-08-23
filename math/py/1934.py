import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    for j in range(1, max(a, b)+1):
        if (a%j==0 and b%j==0):
            ans = j
    print(int(a*b/ans))