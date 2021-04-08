data = []
for i in range(9):
    data.append(int(input()))

print(max(data))

for i in range(9):
    if max(data) == data[i]:
        print(i + 1)