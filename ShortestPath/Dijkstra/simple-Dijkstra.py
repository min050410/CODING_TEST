import sys
input = sys.stdin.readline
INF = int(1e9)
# 노드의 개수, 간선의 개수
n, m = map(int, input().split())
# 시작 노드
start = int(input())
# 노드의 정보 list
graph = [[] for _ in range(n+1)]
# 방문했는지 checklist
visited = [False] * (n+1)
# 시작에서 특정 노드까지의 거리
distance = [INF] * (n+1)

# 간선 정보 입력받기
# _ 은 단순히 input 만 받기 때문에 사용
for _ in range(m):
    a, b, c = map(int, input().split())
    # b : node, c : cost
    graph[a].append((b , c))

# 방문하지 않은 노드 중에서 가장 최단 거리가 짧은 노드의 번호를 반환
def get_smallest_node():
    min_value = INF
    index = 0 #가장 최단 거리가 짧은 노드, 인덱스
    for i in range(1, n+1):
        # distance 리스트를 살피고 INF는 당연히 거르고 min_value보다 작고 방문안한 가장 최솟값을 구함  
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            # index 얻기
            index = i
    return(index)

def dijkstra(start):
    # 시작 노드에 대해서 초기화
    # 재귀 없음
    distance[start] = 0
    visited[start] = True
    # graph[start] 의 형태는 [(n, m), ...]
    for j in graph[start]:
        # distance node index 에 거리 넣기
        distance[j[0]] = j[1]
    # 시작 노드를 제외한 n-1노드에 대해 반복
    # 반복 횟수는 n-1 무조건 반복한다
    # i 는 사용 안함
    for i in range(n-1):
        # 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        # 여기서 개선된 다익스트라는 우선순위 큐에서 꺼냄 
        now = get_smallest_node()
        visited[now] = True
        # 위의 distance에 넣는 형태와 동일 j[i]을 추가로 더한 상태 / 구했던 거리 + 현재 거리 = 현재의 노드까지 오는 거리
        # log(n^2) 원인
        for j in graph[now]:
            cost = distance[now] + j[1]
        # distance[j[0]] 는 지난번에 구해놨던 것 / 안구했으면 초깃값 inf로 들어옴
            if cost < distance[j[0]]:
                distance[j[0]] = cost

dijkstra(start)

# distance[] 순서대로 출력
for i in range(1, n+1):
    if distance[i] == INF:
        print("한무")
    else:
        print(distance[i])

