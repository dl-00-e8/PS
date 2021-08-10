import sys

n, r = map(int, sys.stdin.readline().split())

up, down = 1, 1
if (n - r) > r:
    for i in range(n, n - r, - 1):
        up *= i
    for j in range(1, r + 1):
        down *= j
    print(up // down)
else:
    for i in range(n, r, - 1):
        up *= i
    for j in range(1, n - r + 1):
        down *= j
    print(up // down)
'''
nCm : n! / (n - r)! * r!
1) n ~ r 까지의 곱 / r!
2) n ~ n - r 까지의 곱 / r!
--> 두가지의 방법 중 선택해서 진행되도록 구현
'''