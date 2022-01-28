# 개선된 다익스트라

import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

# 노드의 개수, 간선의 개수를 입력받기
n, m = map(int, input().split())
# 시작 노드 번호 입력받기
start = int(input())
# 정보 리스트 만들기
graph = [[] for _ in range(n+1)]
# 최단 거리 테이블을 모두 무한으로 초기화
distance = [INF] * (n+1)

# 모든 간선 정보를 입력받기
for _ in range(m):
    a,b,c = map(int, input().split())
    graph[a].append(b,c)

def dijkstra(start):
    q = []
    # 시작 노드로 가기 위한 최단 경로를 0으로 설정, 큐에 삽입
    heapq.heappush(q, (0, start))
    # 시작 노드와의 거리 0으로 설정
    distance[start] = 0
    # Queue가 빌때까지 반복(중요)
    while q:
        #가장 짧은 노드에 대한 정보 꺼내기
        dist, now = heapq.heappop()
        # 현재 노드가 이미 처리된 노드라면 무시
        if distance[now] < dist: #INF라면 거짓이 됨
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]: #더 짧을 경우
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

for i in range(1, n+1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])

# 시간복잡도 O(NlogN)
            
