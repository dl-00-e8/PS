import sys
import heapq

n = int(sys.stdin.readline())

heap = []
for i in range(n):
    num = int(sys.stdin.readline())

    if num == 0:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, num)