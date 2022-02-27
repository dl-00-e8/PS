from collections import deque


def bfs(n, k):
    q = deque([n])

    while q:
        now = q.popleft()

        if now == k:
            return visited[now]

        move = [now + 1, now - 1, now * 2]
        for i in move:
            if i >= 0 and i < 100001 and not visited[i]:
                visited[i] = visited[now] + 1
                q.append(i)


n, k = map(int, input().split())

visited = [0] * 100001
print(bfs(n, k))


'''
풀이 방식 : BFS (너비 우선 탐색)
직선 거리가 최대 100,000
이미 방문했던 장소라면, 다시 방문하는 것은 동선 낭비가 되므로 visited 리스트를 사용하여 방지
만약 방문하지 않고, 범위에 맞는다면 기존 배열의 값에 1을 더해서 시간 카운팅을 함.
최종 조건은 방문한 위치가 도착지 위치와 일지할 경우, return하는 방식
위의 조건을 바탕으로 큐를 이용하여 BFS를 진행
'''