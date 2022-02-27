import sys

t = int(sys.stdin.readline())


def solution(num):
    if num == 1:
        return 1
    elif num == 2:
        return 2
    elif num == 3:
        return 4
    else:
        return solution(num - 1) + solution(num - 2) + solution(num - 3)


for _ in range(t):
    n = int(sys.stdin.readline())
    print(solution(n))