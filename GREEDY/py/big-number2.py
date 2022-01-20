# 큰 수의 법칙 풀이 2 - 수열
# 2019 교육기관 코딩 테스트

n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort(reverse=True)
first = data[0]
second = data[1]

# first 가 등장하는 횟수
f_count = (m//(k+1))*k+m%(k+1)
# second 가 등장하는 횟수
s_count = (m//(k+1))

result = f_count*first+s_count*second
print(result)

# 7:45