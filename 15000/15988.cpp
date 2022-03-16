#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int t, n;
ll dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    memset(dp, 0, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 1000001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }

    while(t--) {
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}