n, m = map(int, input().split())
data = list(map(int, input().split()))

result = 0
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            if data[i] + data[j] + data[k] > result and data[i] + data[j] + data[k] <= m:
                result = data[i] + data[j] + data[k]
            else:
                continue

print(result)