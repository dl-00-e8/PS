n = int(input())

for _ in range(n):
    cnt = 1
    score = 0
    data = list(input())
    for i in range(len(data)):
        if data[i] == 'O':
            score += cnt
            cnt += 1
        elif data[i] == 'X':
            cnt = 1
        elif i == len(data) - 1 and data[i] == 'O':
            cnt += 1
            score += cnt
    print(score)