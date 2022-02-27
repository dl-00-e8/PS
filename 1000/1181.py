n = int(input())

voca = []
for _ in range(n):
    voca.append(input())

voca = list(set(voca))

voca = sorted(voca, key = lambda x:(len(x), x))
'''
lambda x:(len(x), x)의 의미
len(x) 길이 순으로 내림 차순 정렬을 한 이후
단어의 사전 순으로 정렬하겠다는 의미
lambda 함수 사용법 조금 더 익힐 필요성 있음
'''

for vocab in voca:
    print(vocab)