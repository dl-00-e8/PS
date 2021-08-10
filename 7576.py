from collections import deque


def bfs(graph, q):
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx and nx < n and 0 <= ny and ny < m:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = graph[x][y] + 1
                    q.append((nx, ny))


# m = 열 / n = 행
m, n = map(int, input().split())

graph = []
q = deque()
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(m):
        if graph[i][j] == 1:
            q.append((i, j))

# 위, 아래, 왼, 오
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

bfs(graph, q)

result = 0
answer = True
for i in range(n):
    for j in range(m):
        if graph[i][j] > 0:
            result = max(result, graph[i][j])
        elif graph[i][j] == 0:
            answer = False

if not answer:
    print(-1)
else:
    print(result - 1)

'''
BFS 구현 문제
dx, dy로 방향성 정의해서 퍼져 나갈 수 있도록 해야한다.
'''