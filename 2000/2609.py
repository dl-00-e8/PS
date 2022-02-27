n, m = map(int, input().split())

data = []
for i in range(10000, 0, -1):
    if n % i == 0 and m % i == 0:
        data.append(i)
        n //= i
        m //= i

min_result = 1
for i in range(len(data)):
    min_result *= data[i]

max_result = min_result * n * m

print(min_result)
print(max_result)