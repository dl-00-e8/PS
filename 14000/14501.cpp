#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int t[16];
int pay[16];
int dp[16];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> t[i] >> pay[i];
    }

    solve();

    return 0;
}

void solve() {
    // 맨 마지막 idx 여부 확인
    if(t[n] != 1) {
        dp[n] = 0;
    }
    else {
        dp[n] = pay[n];
    }

    // Top down DP
    for(int i = n - 1; i > 0; i--) {
        if(i + t[i] - 1 > n) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[i + t[i]] + pay[i]);
        }
    }

    /*
    for(int i = 1; i < n + 1; i++) {
        cout << dp[i] << " ";
    }
    */

    cout << dp[1] << endl;
}