#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
ll dp[1001];
ll solve(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    cout << solve(n) << endl;

    return 0;
}

ll solve(int n) {
    if(dp[n]) {
        return dp[n];
    }

    dp[n] = solve(n - 1) + solve(n - 2) * 2;
    dp[n] %= 10007;

    return dp[n];
}