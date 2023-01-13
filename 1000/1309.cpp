#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
ll dp[100001][2];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;

    solve();

    cout << (dp[n][0] + 2 * dp[n][1]) % 9901 << endl;

    return 0;
}

void solve() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i < n + 1; i++) {
        dp[i][0] = dp[i - 1][0] + 2 * dp[i - 1][1] % 9901;
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] % 9901;
    }
}