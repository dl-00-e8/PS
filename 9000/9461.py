# 9461 파도반 수열
t = int(input())

data = [1] * (101)
data[4] = 2
data[5] = 2
for i in range(6, 101):
    data[i] = data[i - 1] + data[i - 5]

for _ in range(t):
    ind = int(input())
    print(data[ind])