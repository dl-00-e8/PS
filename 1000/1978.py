n = int(input())
data = list(map(int, input().split()))

result = 0
for i in data:
    value = True
    if i > 1:
        for div in range(2, i):
            if i % div == 0:
                value = False
                continue
        if value:
            result += 1

print(result)