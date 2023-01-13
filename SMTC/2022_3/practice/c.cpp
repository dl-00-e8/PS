#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dp[16];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;

    solve();

    cout << dp[n] << endl;

    return 0;
}

void solve() {
    dp[1] = 2;
    for(int i = 2; i < 16; i++) {
        dp[i] = dp[i - 1] * 3;
    }
}