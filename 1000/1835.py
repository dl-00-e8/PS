n = int(input())

card = [n]
for i in range(n-1, 0, -1):
    card = [i] + card
    for j in range(i):
        temp = card[0:n-i]
        card = [card[n-i]] + temp

for i in range(n):
    print(card[i], end= ' ')