import copy
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

        resultWay[now].append(now)

        for i in bus[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
                resultWay[i[0]] = copy.deepcopy(resultWay[now])


n = int(input())
m = int(input())

bus = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, dist = map(int, input().split())
    bus[a].append((b, dist))

distance = [INF] * (n + 1)
resultWay = [[] for _ in range(n + 1)]

start, end = map(int, input().split())

dijkstra(start)

print(distance[end])
print(len(resultWay[end]))
print(*resultWay[end])

'''
단순한 최단 거리 문제이나,
출발지와 도착지가 명확하게 지정되있을 때의 경로를 자세하게 표현하는 것을 조심해야 하는 문제이다.
출발지와 도착지가 명확하게 지정되어 있으므로, resultWay라는 이차원 리스트를 사용하여서 각 도시 별로의 최단 거리를 저장할 수 있도록 구현하였다. '''