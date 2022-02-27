n = int(input())

a_list = list(map(int, input().split()))
b_list = sorted(a_list)

p = []

for i in range(n):
    temp = b_list.index(a_list[i])
    p.append(temp)
    b_list[temp] = -1

for i in range(len(p)):
    if i == len(p) - 1:
        print(p[i])
        break
    print(p[i], end = " ")