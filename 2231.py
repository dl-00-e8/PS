n = int(input())

result = 0
for i in range(1, n + 1):
    data = list(map(int, str(i)))
    result = i + sum(data)
    if result == n:
        print(i)
        break
    
    if i == n:
        print(0)


'''
분해합 : n과 n을 이루는 각 자리수의 합
m의 분해합이 n인 경우, m을 n의 생성자라고 함
n의 가장 작은 생성자를 구해내는 프로그램 구하기
--> 브루스포스로 완전탐색해야함
범위는 입력받은 값까지
'''