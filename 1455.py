def change(n_list, a, b):
    for i in range(a + 1):
        for j in range(b + 1):
            n_list[i][j] = 1 - n_list[i][j]


n, m = map(int, input().split())

coin = []
for i in range(n):
    coin.append(list(map(int, input())))

cnt = 0
for i in range(n - 1, -1, -1):
    for j in range(m - 1, -1, -1):
        if coin[i][j] != 0:
            change(coin, i, j)
            cnt += 1

print(cnt)