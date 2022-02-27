import sys

input = sys.stdin.readline

line = input()
line = line.rstrip()
bomb = input()
bomb = bomb.rstrip()

stack = []
for i in line:
    stack.append(i)

    if i == bomb[len(bomb) - 1]:
        if ''.join(stack[len(stack) - len(bomb):]) == bomb:
            for _ in range(len(bomb)):
                stack.pop()

if len(stack) == 0:
    print('FRULA')
else:
    for i in stack:
        print(i, end = '')
    print()

'''
join으로 합쳐서 bomb랑 비교해야함
join을 쓰지 않고 푼다면, bomb는 str이고, stack은 list이기 때문에 type불일치로
인해서 해당 조건문을 통과할 수 없음

시작 기준으로 cnt 변수를 이용해서 cnt하는 것은 cc44와 같이 겹쳐있을 때 정상적으로 사용불가
'''