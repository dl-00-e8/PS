import sys

input = sys.stdin.readline


def knapSack(stuff, n, k):
    dp = [[0] * (k + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if j >= stuff[i][0]:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuff[i][0]] + stuff[i][1])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][k]


n, k = map(int, input().split())

stuff = [(0, 0)]
for _ in range(n):
    w, v = map(int, input().split())
    stuff.append((w, v))

print(knapSack(stuff, n, k))