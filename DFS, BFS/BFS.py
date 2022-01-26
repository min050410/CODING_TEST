from collections import deque

# BFS 메서드
def bfs(graph, start, visited):
    # queue 구현
    queue = deque([start])
    # 방문처리
    visited[start] = True
    # queue가 빌 때까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()
        print(v, end=" ")
        # 해당 원소와 연결된, 방문하지 않은 원소를 큐에 삽입
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

visited = [False] * 9

# index 1 부터 시작
bfs(graph, 1, visited)

# 출력값
# 1 2 3 8 7 4 5 6
