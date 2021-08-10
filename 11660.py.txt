import sys

input = sys.stdin.readline


def prefixSum(prefix, x1, y1, x2, y2):
    result = 0
    for i in range(x2, x1 - 1, -1):
        result += (prefix[i][y2] - prefix[i][y1 - 1]) 

    return result


n, m = map(int, input().split())

graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

prefix = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        prefix[i][j] = prefix[i][j - 1] + graph[i - 1][j - 1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    print(prefixSum(prefix, x1, y1, x2, y2))