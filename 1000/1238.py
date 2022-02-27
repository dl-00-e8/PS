import sys
import heapq

INF = int(1e9)
input = sys.stdin.readline


def dijkstra(start, x):
    distance = [INF] * (n + 1)
    
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
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    
    if x == 0:
        return distance
    elif x > 0:
        return distance[x]


n, m, x = map(int, input().split())

graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, dist = map(int, input().split())
    graph[a].append((b, dist))

student = dijkstra(x, 0)
for i in range(1, n + 1):
    if i == x:
        student[i] = 0
        continue
    
    student[i] += dijkstra(i, x)

print(max(student[1:]))