from collections import deque

# deque 라이브러리 사용
queue = deque()

# 삽입 - inqueue
queue.append(5)
queue.append(2)
queue.append(3)
queue.append(7)

# 삭제 - dequeue
queue.popleft()

# inqueue
queue.append(1)
queue.append(4)

# dequeue
queue.popleft()

print(queue)
queue.reverse()
print(queue)

