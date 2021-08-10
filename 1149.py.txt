n = int(input())

house = []
for _ in range(n):
    house.append(list(map(int, input().split())))

dp = [[0] * 3 for _ in range(n)]
dp[0][0] = house[0][0]
dp[0][1] = house[0][1]
dp[0][2] = house[0][2]
for i in range(1, n):
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2]

print(min(dp[n - 1]))

'''
풀이 방법 : DP
처음엔 맨 첫번째 배열의 min값을 index로 잡아서 index + 1, index - 1로 조정해가면서 min을 찾는 방식을 구현하였으나, RGB 값이 동일하게 입력되는 경우에 대해 min과 index가 정상적으로 작동할 수 없었다.
그리하여, dp테이블을 house와 동일하게 구현한 뒤에, 모든 색깔에 대해서 각각 dp 점화식을 진행하여 그 중 가장 작은 값을 출력하도록 구현하였다.
'''