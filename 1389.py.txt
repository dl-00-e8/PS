from collections import deque


def bfs(graph, start):
    result = [0] * (n + 1)
    visited = [False] * (n + 1)
    q = deque([start])
    visited[start] = True
    while q:
        now = q.popleft()
        visited[now] = True
        for i in graph[now]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
                result[i] = result[now] + 1

    return sum(result)


n, m = map(int, input().split())

graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

output = []
for i in range(1, n + 1):
    output.append(bfs(graph, i))

print(output.index(min(output)) + 1)