# 숫자 카드 게임 
# 2019 국가 교육기관 코딩 테스트

n, m = map(int, input().split())

min_list = []

for i in range(n):
    data = list(map(int, input().split()))
    min_list.append(min(data))

result = max(min_list) 
print(result)

# 5:53

