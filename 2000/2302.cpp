#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
vector<int> sit;
int dp[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int input;
        cin >> input;
        sit.push_back(input);
    }

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int answer = 1;
    int last_idx = 0;
    for(auto s: sit) {
        answer *= dp[s - last_idx - 1];
        last_idx = s;
    }
    if(last_idx < N) {
        answer *= dp[N - last_idx];
    }

    cout << answer << endl;

    return 0;
}

/**
 * 고정석을 기준으로 여러 개로 쪼개버린다.
 * 각 쪼개진 애들끼리 DP를 통해서 구한다. -> 방법의 가짓수를 서로 곱한다.
 * 백트래킹 방식으로는 풀 수 없을까?
 * 좌석이 한 개라면? -> 경우의 수는 1
 * 좌석이 두 개라면? -> 경우의 수는 2
 * 좌석이 세 개라면? -> 경우의 수는 3
 * 좌석이 네 개라면? -> 경우의 수는 5
 * 1 2 3 4
 * 2 1 3 4
 * 1 2 4 3
 * 2 1 4 3
 * 1 3 2 4
 * 좌석이 다섯 개라면? -> 경우의 수는
 * 1 2 3 4 5
 * 2 1 3 4 5
 * 1 3 2 4 5
 * 1 2 4 3 5
 * 1 2 3 5 4
 * 2 1 4 3 5
 * 2 1 3 5 4
 * 
 * 좌석이 N개라고 했을 때,
 * N번째 좌석을 그대로 앉는다. -> dp[N - 1]만큼의 경우의 수가 생긴다.
 * N번째 좌석인 애가 N - 1번째 앉는 경우 -> N, N-1은 바뀌었으므로 dp[N - 2]의 경우의 수가 생긴다.
 */