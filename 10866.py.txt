import sys
from collections import deque

n = int(sys.stdin.readline())

q = deque()
for _ in range(n):
    temp = list(map(str, sys.stdin.readline().split()))
    
    if temp[0] == 'push_front':
        q.appendleft(int(temp[1]))
    elif temp[0] == 'push_back':
        q.append(int(temp[1]))
    elif temp[0] == 'pop_front':
        if len(q) == 0:
            print(-1)
            continue
        print(q.popleft())
    elif temp[0] == 'pop_back':
        if len(q) == 0:
            print(-1)
            continue
        print(q.pop())
    elif temp[0] == 'size':
        print(len(q))
    elif temp[0] == 'empty':
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif temp[0] == 'front':
        if len(q) == 0:
            print(-1)
            continue
        print(q[0])
    elif temp[0] == 'back':
        if len(q) == 0:
            print(-1)
            continue
        print(q[-1])
        
