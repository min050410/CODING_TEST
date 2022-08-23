import sys
input = sys.stdin.readline

list = [31,28,31,30,31,30,31,31,30,31,30,31]
day = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']

n, m = map(int, input().split())

cnt = 0
for i in range(n-1):
    cnt+=list[i]

cnt += m
print(day[(cnt % 7)-1])

