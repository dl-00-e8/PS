n = int(input())

stairs = [0] * (n + 3)
dp = [0] * (n + 3)
for i in range(1, n + 1):
    stairs[i] = int(input())

dp[1] = stairs[1]
dp[2] = stairs[1] + stairs[2]
dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3])

for i in range(4, n + 1):
    dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i])

print(dp[n])

'''
N = int(input())
dp = [0 for _ in range(N+3)]
arr = [0 for _ in range(N+3)]
for k in range(1,N+1):
    arr[k] = int(input())


dp [1] = arr[1]
dp [2] = arr[1] + arr[2]
dp [3] = max(arr[1] + arr[3] ,arr[2] + arr[3])


for i in range(4, N+1):
    dp[i] = max( dp[i-3] + arr[i-1] + arr[i] ,  dp[i-2] + arr[i] ) 
print(dp[N])
'''