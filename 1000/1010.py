import sys
import operator
from functools import reduce


def combination(n, r):
    if n < 1 or r < 0 or n < r:
        return -1
    r = min(r, n - r)
    numerator = reduce(operator.mul, range(n, n - r, -1), 1)
    denominator = reduce(operator.mul, range(1, r + 1), 1)
    return numerator // denominator


t = int(sys.stdin.readline())
for _ in range(t):
    a, b = map(int, sys.stdin.readline().split())
    print(combination(b, a))
