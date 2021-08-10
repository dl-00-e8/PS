import sys
import heapq

INF = int(1e9)


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]]= cost
                heapq.heappush(q, (cost, i[0]))


v, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

distance = [INF] * (v + 1)
graph = [[] for _ in range(v + 1)]
for _ in range(e):
    a, b, dist = map(int, sys.stdin.readline().split())
    graph[a].append((b, dist))

dijkstra(k)

for i in range(1, v + 1):
    if distance[i] == INF:
        print('INF')
        continue
    
    print(distance[i])