# 이진 탐색 구현
def binary_search(array, target, start, end):
    # start가 커진다면 찾는 값이 없다는 의미
    if start > end:
        return None
    # mid 구하기
    mid = (start + end)//2
    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return binary_search(array, target, start, mid-1)
    else:
        return binary_search(array,target, mid+1,end)

# 입력
n, target = list(map(int, input().split()))
array = list(map(int,input().split()))

# 출력
result = binary_search(array, target, 0, n-1)
if result == None:
    print("원소가 존재하지 않습니다")
else:
    print(result + 1)


# 입력
# 10 7
# 1 3 5 7 9 11 13 15 17 19

# 출력
# 4