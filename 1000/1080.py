def change(n_list, a, b):
    for i in range(a, a + 3):
        for j in range(b, b + 3):
            if n_list[i][j] == 0:
                n_list[i][j] = 1
            elif n_list[i][j] == 1:
                n_list[i][j] = 0


n, m = map(int, input().split())

A = []
B = []
for i in range(n):
    A.append(list(map(int, input())))
for i in range(n):
    B.append(list(map(int, input())))

cnt = 0
for i in range(0, n - 2):
    for j in range(0, m - 2):
        if A[i][j] != B[i][j]:
            change(A, i, j)
            cnt += 1

result = False
for i in range(0, n):
    for j in range(0, m):
        if A[i][j] != B[i][j]:
            result = True

if(result):
    print(-1)
else:
    print(cnt)
