n = int(input())
time = list(map(int, input().split()))

time.sort()

result = []
for i in range(n):
    temp = sum(time[:i])
    result.append(temp + time[i])

print(sum(result))
