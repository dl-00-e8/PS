t = int(input())

data = [[1, 0], [0, 1]]

for i in range(2, 41):
    zero = data[i - 1][0] + data[i - 2][0]
    one = data[i - 1][1] + data[i - 2][1]
    data.append([zero, one])

for _ in range(t):
    n = int(input())

    if n == 0:
        print(data[0][0], data[0][1])
    elif n == 1:
        print(data[1][0], data[1][1])
    else:
        print(data[n][0], data[n][1])

'''
피보나치 수열의 호출 수를 구하라

Q. 단순하게 fibonacci 함수를 이용해서 재귀를 시키면 무조건 시간 초과가 난다.
시간초과를 어떻게 줄일것인가?
A. DP에서 재귀방식이 아닌 계산방식을 따로 구현한다.

Q. fibonacci 함수의 호출방식을 이용한 식 구현
A. n <= 40인 자연수이므로, 바텀업 방식으로 메모이제이션 활용해서 값을 다 저장해놓고 호출하는 방식으로 구현하자.
'''