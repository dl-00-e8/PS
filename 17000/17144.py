import sys
from copy import deepcopy

input = sys.stdin.readline


def dirty(graph, airClear):
    temp = [[0] * c for i in range(r)]
    temp[airClear[0][0]][airClear[0][1]] = -1
    temp[airClear[1][0]][airClear[1][1]] = -1
    for i in range(r):
        for j in range(c):
            if graph[i][j] > 0:
                cnt = 0
                for k in range(4):
                    x = i + dx[k]
                    y = j + dy[k]
                    if (0 <= x < r) and (0 <= y < c) and graph[x][y] != -1:
                        temp[x][y] += graph[i][j] // 5
                        cnt += 1
                temp[i][j] += graph[i][j] - (graph[i][j] // 5 * cnt)
    return temp


def clean(x, y, airType):
    temp = deepcopy(graph)
    cx, cy = x, y - 1
    graph[x][y] = 0
    for i in range(4):
        while True:
            nx = x + dx[airType[i]]
            ny = y + dy[airType[i]]
            
            if nx == cx and ny == cy:
                return
            
            if (0 <= nx < r) and (0 <= ny < c):
                graph[nx][ny] = temp[x][y]
            else:
                break
                
            x, y = nx, ny


r, c, t = map(int, input().split())

graph = [[0] * (c) for _ in range(r)]
airClear = []
dirt = []
for i in range(r):
    tempLine = list(map(int, input().split()))
    for j in range(c):
        if tempLine[j] == -1:
            airClear.append([i, j])

        graph[i][j] = tempLine[j]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(t):
    graph = dirty(graph, airClear)
    clean(airClear[0][0], airClear[0][1] + 1, [3, 0, 2, 1])
    clean(airClear[1][0], airClear[1][1] + 1, [3, 1, 2, 0])

sumValue = 0
for i in range(r):
    sumValue += sum(graph[i])

print(sumValue + 2)
