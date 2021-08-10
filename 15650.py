import sys

input = sys.stdin.readline


def check(x):
    if x == m + 1:
        for i in range(1, m + 1):
            print(arr[i], end = ' ')
        print()
    else:
        for i in range(1, n + 1):
            if max(arr) < i:
                arr[x] = i
                check(x + 1)
                arr[x] = 0


n, m = map(int, input().split())

arr = [0] * (m + 1)

check(1)