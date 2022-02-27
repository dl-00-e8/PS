n = int(input())
line = list(map(int, input().split()))

result = [0] * n

data = 1
for i in line:
    cnt = 0
    for j in range(n):
        if cnt == i and result[j] == 0:
            result[j] = data
            break
        if result[j] == 0:
            cnt += 1
    data += 1

for i in range(n):
    if i == n - 1:
        print(result[i])
        break
    print(result[i], end = " ")