# 값 입력받기
data = []
for _ in range(n):
    data.append(int(sys.stdin.readline()))

# 결과 변수 및 이미 한 번 체크하였었던 수인지를 확인하기 위한 리스트 선언
result = 0
already = [0] * 1000001

# 확인 진행
for i in data:
    if already[i]:
        continue
    already[i] = 1
    cur = data[0]
    cnt = 1
    for j in range(1 ,len(data)):
        if i == data[j]:
            continue
        if cur == data[j]:
            cnt += 1
        else:
            cur = data[j]
            cnt = 1
        result = max(result, cnt)

print(result)