#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
ll dp[61][61];
ll solve(int one, int half);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        memset(dp, -1, sizeof(dp));

        cin >> n;

        if(n == 0) {
            break;
        }

        cout << solve(n - 1, 1) << endl;
    }

    return 0;
}

ll solve(int one, int half) {
    if(one == 0) {
        return 1;
    }

    if(dp[one][half] != -1) {
        return dp[one][half];
    }

    dp[one][half] = 0;

    if(one > 0) {
        dp[one][half] += solve(one - 1, half + 1);
    }
    if(half > 0) {
        dp[one][half] += solve(one, half - 1);
    }

    return dp[one][half];
}