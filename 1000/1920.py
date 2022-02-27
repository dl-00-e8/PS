import sys


def binary_Search(a, a_list, b):
    left = 0
    right = a - 1

    while left <= right:
        mid = (left + right) // 2
        if a_list[mid] > b:
            right = mid - 1
        elif a_list[mid] < b:
            left = mid + 1
        elif a_list[mid] == b:
            return 1
    return 0


n = int(sys.stdin.readline())
n_list = list(map(int, sys.stdin.readline().split()))
n_list.sort()

m = int(sys.stdin.readline())
m_list = list(map(int, sys.stdin.readline().split()))

for i in m_list:
    print(binary_Search(n, n_list, i))

'''
시간 초과가 발생함
즉, 탐색하는데 걸리는 시간이 굉장히 많음
이를 축소 시켜야 함 --> 이진탐색
'''