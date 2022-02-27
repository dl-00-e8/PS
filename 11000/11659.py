import sys

n, m = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))

sumValue = 0
prefixSum = [0]
for i in num:
    sumValue += i
    prefixSum.append(sumValue)

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(prefixSum[j] - prefixSum[i - 1])

'''
input().split()으로 하였더니 시간초과
import sys 후, sys.stdin.readline().split()으로 변경하였더니 정답
'''