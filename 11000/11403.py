INF = int(1e9)

n = int(input())

graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(n):
        if graph[i][j] == 0:
            graph[i][j] = INF
    
for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(n):
    for j in range(n):
        if graph[i][j] == INF:
            print(0, end = " ")
        else:
            print(1, end = " ")
    print()
'''
문제 풀이 : 플로이드 와샬
'''