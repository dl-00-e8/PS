n = int(input())

data = []
for i in range(n):
    data.append(list(map(int, input().split())))

data.sort()

for i in range(n):
    print(data[i][0], data[i][1])