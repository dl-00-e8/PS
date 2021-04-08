n, m = map(int, input().split())

data = []
for _ in range(n):
    data.append(list(input()))

def color_changer(color):
    if color == 'W':
        return 'B'
    elif color == 'B':
        return 'W'

result = 9999
for clr in ['W', 'B']:
    cnt = 0
    for x in range(n):
        for y in range(m):
            if data[x][y] == clr:
                clr = color_changer(clr)
            else:
                cnt += 1
                clr = color_changer(clr)
        clr = color_changer(clr)
    result = min(cnt, result)

print(result)