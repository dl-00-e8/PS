INF = int(1e9)


def floyd(graph, n):
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    
    return graph


n, m, r = map(int, input().split())
t = list(map(int, input().split()))

graph = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a][b] = l
    graph[b][a] = l

graph = floyd(graph, n)

result = 0
for i in range(1, n + 1):
    cnt = t[i - 1]
    for j in range(1, n + 1):
        if i == j:
            continue

        if graph[i][j] <= m:
            cnt += t[j - 1]

    result = max(result, cnt)

print(result)

'''
플로이드 워셜로 모든 노드 간의 최단 거리 구한 이후
이중반복문으로 최대 아이템 개수 확인
'''