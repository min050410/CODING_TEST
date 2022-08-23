import sys
input = sys.stdin.readline 

p = [0]*10000
p[1] += 1
p[2] += 1
p[3] += 1
p[4] += 2
p[5] += 2
n = int(input())
for _ in range(n):
    a = int(input())
    for i in range(6, a+1):
        if p[i]: continue
        else: p[i] = p[i-1] + p[i-5]
    print(p[a])
 