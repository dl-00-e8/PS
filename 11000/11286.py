import sys
import heapq

n = int(sys.stdin.readline())

heap = []
data = {}
for _ in range(n):
    x = int(sys.stdin.readline())
    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            temp = heapq.heappop(heap)
            if temp in data:
                if data[temp] != 0:
                    data[temp] -= 1
                    print(-temp)
                else:
                    print(temp)
            else:
                print(temp)
    else:
        if x < 0:
            heapq.heappush(heap, abs(x))
            if abs(x) in data:
                data[abs(x)] += 1
            else:
                data[abs(x)] = 1
        elif x > 0:
            heapq.heappush(heap, x)
