import sys
while True:
    try:
        gps = list(map(int, input().split()))
        gps.sort()
        length = max(gps[1] - gps[0], gps[2] - gps[1])
        print(length - 1)
    except Exception as e:
        exit()

'''
gps = list(map(int, input().split()))
gps.sort()
length = max(gps[1] - gps[0], gps[2] - gps[1])
print(length - 1)
2965번 정답
'''