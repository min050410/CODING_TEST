# 큰 수의 법칙
# 2019 교육기관 코딩 테스트

n, m, k = map(int, input().split())
data = list(map(int, input().split()))

ori_k = k

data.sort(reverse=True)

count = 0

while m!=0:
    if(k!=0):
        count += data[0]
        k -= 1
    else:
        count += data[1]
        k = ori_k
    m -= 1

print(count)

# 14:17

