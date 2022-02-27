import sys

# sys.setrecursionlimit(10**9) 
# python3로 채점할 때는 문제가 없었지만, pypy3로 채점할 때에는 메모리 초과
# 의 원인이 됨

input = sys.stdin.readline


def dfs(tree, v, result):
    for i in tree[v]:
        if result[i[0]] == 0:
            result[i[0]] = result[v] + i[1]
            dfs(tree, i[0], result)


v = int(input())
tree = [[] for _ in range(v + 1)] 

for i in range(1, v + 1):
    temp = list(map(int, input().split()))
    for j in range(len(temp)):
        if temp[j] == -1:
            break

        if j == 0:
            node = temp[j]
            continue
        
        if j % 2 == 0:
            tree[node].append((temp[j - 1], temp[j]))
        else:
            continue

resultFirst = [0] * (v + 1)
dfs(tree, 1, resultFirst)
last = resultFirst.index(max(resultFirst))
resultFirst[1] = 0

resultLast = [0] * (v + 1)
dfs(tree, last, resultLast)
resultLast[last] = 0
print(max(resultLast))

'''
중요!
트리의 지름은 아무 노드에서 bfs(or dfs)를 통해 가장 멀리있는 노드를 구한 후
해당 노드에서 bfs(or dfs)를 한번 더 진행하여 가장 멀리있는 노드를 구하면 된다.

단, 루트 노드가 정해져 있지 않은 상태로 양방향으로 입력을 받기 때문에 시작 값에
대하여서 result내의 value를 0으로 처리해주어야 한다.
'''