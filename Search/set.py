# 부품 찾기

# N 가게의 부품 개수 입력받기
n = int(input())

# 가게에 있는 전체 부품번호를 입력받아서 집합 자료형에 기록
array = set(map(int, input().split()))

# 손님이 확인 요청한 부품 개수를 입력받기
m = int(input())

# 손님이 확인 요청한 전체 부품 번호를 공백으로 구분하여 입력
x = list(map(int, input().split()))

for i in x:
    if i in array:
        print('yes', end=' ')
    else:
        print('no', end=' ')