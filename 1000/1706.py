# 1706 크로스 워드
r, c = map(int, input().split())

data = [list(input()) for _ in range(r)]

voca = []
temp = ''
# 가로로 단어 찾기
for i in range(r):
    for j in range(c):
        if j == c - 1 and data[i][j] != '#':
            temp += data[i][j]
            if len(temp) == 1:
                temp = ''
                continue
            voca.append(temp)
            temp = ''
            continue
        if data[i][j] != '#':
            temp += data[i][j]
        else:
            if temp == '' or len(temp) == 1:
                temp = ''
                continue
            voca.append(temp)
            temp = ''

# 세로로 단어 찾기
for i in range(c):
    for j in range(r):
        if j == r - 1 and data[j][i] != '#':
            temp += data[j][i]
            if len(temp) == 1:
                temp = ''
                continue
            voca.append(temp)
            temp = ''
            continue
        if data[j][i] != '#':
            temp += data[j][i]
        else:
            if temp == '' or len(temp) == 1:
                temp = ''
                continue
            voca.append(temp)
            temp = ''

voca.sort()
print(voca[0])