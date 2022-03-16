#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    memset(dp, 0, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n + 1; i++) {
        dp[i] = (dp[i - 1] + dp[i -2]) % 10007;
    }

    cout << dp[n] << endl;

    return 0;
}