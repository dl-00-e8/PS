#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
int cnt[201];
int preSum[201];
int dp[300001];
int recursive(int now); // depth는 현재 idx, now는 남은 대포 수
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cnt, 0, sizeof(cnt));
    memset(preSum, 0, sizeof(preSum));
    memset(dp, -1, sizeof(dp));

    cin >> n;

    solve();

    return 0;
}

int recursive(int now) {
    if(now == 0) {
        return 0;
    }

    if(dp[now] != -1) {
        return dp[now];
    }

    dp[now] = INF;
    for(int i = 1; i < 201; i++) {
        if(preSum[i] > now) {
            break;
        }

        dp[now] = min(dp[now], 1 + recursive(now - preSum[i]));
    }

    return dp[now];
}

void solve() {
    for(int i = 1; i < 201; i++) {
        cnt[i] = cnt[i - 1] + i;
        preSum[i] = preSum[i - 1] + cnt[i];
    }

    // 만들 수 있는 경우의 수 찾기
    cout << recursive(n) << endl;
}