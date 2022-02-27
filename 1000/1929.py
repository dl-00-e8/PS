m, n = map(int, input().split())

data = [True] * (n + 1)
data[0] = False
data[1] = False

for i in range(2, int(n ** 0.5) + 1):
    if data[i] == True:
        for j in range(i + i, n + 1, i): 
            data[j] = False
            

for i in range(m, n+1):
    if data[i] == True:
        print(i)