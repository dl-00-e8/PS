t = int(input())
c = []
for i in range(t):
    a = int(input())
    c.append(a)
    
data = [25, 10, 5, 1]
for i in c:
    for j in data:
        result = 0
        result = i // j
        i = i % j
        if j != 1:
            print(result, end = " ")
        else:
            print(result, end = "")
    print(" ")