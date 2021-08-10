import sys
import heapq

n = int(sys.stdin.readline())

h = []
for _ in range(n):
    x = int(sys.stdin.readline())

    if x == 0:
        try:
            print(-heapq.heappop(h))
        except:
            print(0)
    else:
        heapq.heappush(h, -x)

'''
파이썬은 내장 힙이 최소 힙이므로
최대 힙으로 구현하기 위하여 음수 부호를 통해
입력하는 방식으로 변경해주어야 한다.
--> 단순하게 음수부호를 활용하는 방식에서 현재 시간초과 발생
'''