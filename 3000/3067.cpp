#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n, m;
vector<int> coin;
int dp[10001];
int solve(int n, vector<int> coin, int m);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        coin.clear();

        cin >> n;
        for(int i = 0; i < n; i++) {
            int input;
            cin >> input;
            coin.push_back(input);
        }
        cin >> m;

        cout << solve(n, coin, m) << endl;
    }

    return 0;
}

int solve(int n, vector<int> coin, int m) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;


    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= m; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }


    return dp[m];
}