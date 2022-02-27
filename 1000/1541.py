data = list(map(str, input()))

result = 0


def math(a, b):
    global result
    if b == '+':
        result += a
    elif b == '-':
        result -= a


def change(temp):
    if temp[0] == '0' and len(temp) > 1:
        temp = temp[1:]
    return int(temp)


cnt = False
num = 0
tool = '+'
temp = ''
for i in range(len(data)):
    if i == len(data) - 1:
        temp += data[i]
        num = change(temp)
        math(num, tool)
        break

    if data[i] == '-' or data[i] == '+':
        if data[i] == '-':
            cnt = True
        num = change(temp)
        math(num, tool)
        if cnt == True:
            tool = '-'
        temp = ''
        continue
    temp += data[i]

print(result)