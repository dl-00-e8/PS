from collections import deque

result1 = []
result2 = []


def dfs(graph, v, visited):
    global result1
    visited[v] = True
    result1.append(v)
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)


def bfs(graph, v, visited):
    q = deque([v])
    visited[v] = True
    while q:
        now = q.popleft()
        result2.append(now)
        for i in graph[now]:
            if not visited[i]:
                q.append(i)
                visited[i] = True


n, m, v = map(int, input().split())

visited1 = [False] * (n + 1)
visited2 = [False] * (n + 1)

graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# graph 내부 정렬 필요 (동일할 연결일 경우, 번호가 낮은 것이 우선으로 빠져나오기 위한 코드)
for i in range(1, n + 1):
    graph[i].sort()

dfs(graph, v, visited1)
bfs(graph, v, visited2)
print(*result1)
print(*result2)