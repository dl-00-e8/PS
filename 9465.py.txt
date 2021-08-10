t = int(input())

for _ in range(t):
    n = int(input())
    data = []
    for _ in range(2):
        data.append(list(map(int, input().split())))
    
    if n > 1:
        data[1][1] += data[0][0]
        data[0][1] += data[1][0]
    
    for i in range(2, n):
        data[0][i] += max(data[1][i - 1], data[1][i - 2])
        data[1][i] += max(data[0][i - 1], data[0][i - 2])

    print(max(data[0][n - 1], data[1][n - 1]))

'''
n == 1일 때에 대한 고려가 되어야 함
if n > 1의 조건문이 필요한 이유
'''