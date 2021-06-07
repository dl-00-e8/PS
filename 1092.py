import sys

# 크레인 수와 크레인의 제한 무게 입력
n = int(sys.stdin.readline())
crane = list(map(int, sys.stdin.readline().split()))
crane.sort(reverse = True)

# 박스 수와 박스의 무게 입력
m = int(sys.stdin.readline())
box = list(map(int, sys.stdin.readline().split()))
box.sort(reverse = True)

# 크레인이 박스 무게를 들지 못할 경우, -1 출력
if crane[0] < box[0]:
        print(-1)
else:
    # 크레인 움직이는 과정
    time = 0
    while True:
        if n < len(box):
            cnt = n
        else:
            cnt = len(box)
        
        for i in range(cnt):
            for j in range(len(box)):
                if crane[i] >= box[j]:
                    del box[j]
                    break
        time += 1
    
        if box == []:
            print(time)
            break
    