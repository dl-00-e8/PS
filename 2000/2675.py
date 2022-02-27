t = int(input())

for i in range(t):
    r, s = input().split()
    string = ''
    for j in s:
        string += j * int(r)
    print(string)