import sys
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t):
    p = sys.stdin.readline()
    n = int(sys.stdin.readline())
    arrInput = sys.stdin.readline()
    arr = list(arrInput[1:-2].split(','))

    if arr[0] != '':
        arr = deque(arr)
    else:
        arr = deque()

    error = False
    turnCnt = 0
    for i in p:
        if i == 'R':
            turnCnt += 1
        elif i == 'D':
            if len(arr) == 0:
                print('error')
                error = True
                break
            if turnCnt % 2 == 0:
                arr.popleft()
            elif turnCnt % 2 == 1:
                arr.pop()

    if p.count('R') % 2 == 1:
        arr.reverse()

    if not error:
        print('[' + ','.join(arr) + ']')

'''
Q. 시간 초과가 발생하는 부분은 어디인가?
A. reverse부분과 리스트 슬라이싱이 발생하는 부분
리스트 슬라이싱을 덱을 활용해 pop과 popleft로 시간 단축
'''