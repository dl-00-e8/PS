from collections import deque

t = int(input())


def giveBook(n, books, students):
    students = sorted(students, key = lambda x : x[1])

    cnt = 0
    while students:
        a, b = students.pop(0)

        for i in range(a, b+1):
            if not books[i]:
                cnt += 1
                books[i] = True
                break
    
    return cnt


for _ in range(t):
    n, m = map(int, input().split())

    books = [False] * (n + 1)
    
    students = []
    for i in range(m):
        students.append(list(map(int, input().split())))

    result = giveBook(n, books, students)
    print(result)
    
