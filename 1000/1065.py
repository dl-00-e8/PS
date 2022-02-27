num = int(input())

if 0 < num and num <= 99:
    print(num)
elif 99 < num and num <= 1000:
    cnt = 99
    for i in range(100, num+1):
        j = str(i)
        n = list(map(int, j))
        if n[0] + n[2] == n[1] * 2:
            cnt += 1
        else:
            continue
    print(cnt)