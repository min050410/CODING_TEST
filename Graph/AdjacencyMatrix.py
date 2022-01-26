from math import inf

INF = inf

# 인접 행렬 AdjacencyMatrix
# 2차원 리스트로 구현
graph = [
    [0, 7, 5],
    [7, 0, INF],
    [5, INF, 0]
]

print(graph)
