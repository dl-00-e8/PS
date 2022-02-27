import sys


def push(a):
    stack.append(a)


def pop():
    if not stack:
        return -1
    else:
        return stack.pop()


def size():
    return len(stack)


def empty():
    if not stack:
        return 1
    else:
        return 0


def top():
    if stack:
        return stack[-1]
    else:
        return -1


n = int(sys.stdin.readline())

stack = []
for i in range(n):
    order = list(sys.stdin.readline().split())
    if order[0] == 'push':
        push(order[1])
    elif order[0] == 'pop':
        print(pop())
    elif order[0] == 'size':
        print(size())
    elif order[0] == 'empty':
        print(empty())
    elif order[0] == 'top':
        print(top())

'''
input() 함수를 사용할 경우, 시간초과 에러가 뜸
시간 단축을 위해서 sys.stdin.readlin()을 사용해야함
입출력 속도 비교 : sys.stdin.readline() > raw_input() > input()

최초 코드
n = int(input())

stack = []
for i in range(n):
    length = len(stack)
    order = list(input().split())
    if order[0] == 'push':
        stack.append(int(order[1]))
    elif order[0] == 'pop':
        if length == 0:
            print('-1')
        else:
            print(stack.pop())
    elif order[0] == 'size':
        print(length)
    elif order[0] == 'empty':
        if length == 0:
            print('1')
        else:
            print('0')
    elif order[0] == 'top':
        if length != 0:
            print(stack[length - 1])
        else:
            print('-1')
'''