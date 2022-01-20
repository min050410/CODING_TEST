# 1이 될 때 까지
# 2018 E 기업 알고리즘 대회

n, k = map(int, input().split())
cnt = 0
while n!=1:
    if(n%k==0):
        n /= k
        cnt += 1
    else:
        n -= 1
        cnt += 1

print(cnt)

# 3:48
