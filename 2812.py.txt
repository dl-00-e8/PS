import sys

input = sys.stdin.readline

n, k = map(int, input().split())
num = list(map(int, input().strip()))

result = []
limit = k
for i in range(n):
    while limit > 0 and len(result) > 0:
        if result[len(result) - 1] < num[i]:
            result.pop()
            limit -= 1
        else:
            break

    result.append(num[i])

for i in range(n - k):
    print(int(result[i]), end = '')

'''
스택의 제일 위의 값과 넣을 값을 비교하며 넣을 값이 클 경우 스택의 제일 위의 값을 제거합니다.
위 행동을 반복하며 넣을 값이 작아질 경우 스택에 넣어줍니다.
'''