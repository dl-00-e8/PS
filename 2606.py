def dfs(graph, start, visited):
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            dfs(graph, i, visited)


n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * (n + 1)

dfs(graph, 1, visited)
print(visited.count(True) - 1)