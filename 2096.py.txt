import sys

n = int(sys.stdin.readline())

dp = [[0] * 3 for _ in range(2)]
dpMin = [[0] * 3 for _ in range(2)]
for i in range(n):
    line = list(map(int, sys.stdin.readline().split()))

    dp[1][0] = line[0] + max(dp[0][0], dp[0][1])
    dp[1][1] = line[1] + max(dp[0][0], dp[0][1], dp[0][2])
    dp[1][2] = line[2] + max(dp[0][1], dp[0][2])

    dpMin[1][0] = line[0] + min(dpMin[0][0], dpMin[0][1])
    dpMin[1][1] = line[1] + min(dpMin[0][0], dpMin[0][1], dpMin[0][2])
    dpMin[1][2] = line[2] + min(dpMin[0][1], dpMin[0][2])

    dp[0][0], dp[0][1], dp[0][2] = dp[1][0], dp[1][1], dp[1][2]
    dpMin[0][0], dpMin[0][1], dpMin[0][2] = dpMin[1][0], dpMin[1][1], dpMin[1][2]

print(max(dp[1]), min(dpMin[1]))

'''
deepcopy 모듈을 사용해서 깊은 복사하려고 했었으나
이 것이 오히려 메모리 초과에 영향을 미치고 있었다.
최소한의 메모리를 사용하여야 할 때에는 deepcopy를
배제하고 문제를 풀 것'''