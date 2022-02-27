n, s, r = map(int, input().split())
slist = list(map(int, input().split()))
rlist = list(map(int, input().split()))

cnt = 0
for i in rlist:
    if cnt == 1:
        cnt = 0
        continue
    for j in slist:
        if j - i >= -1 and j - i <= 1:
            s -= 1
            cnt += 1
            break

print(s)            