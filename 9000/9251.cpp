#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string a, b;
int dp[1001][1001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> a >> b;

    solve();

    return 0;
}

void solve() {
    int result = 0;

    for(int i = 1; i < a.size() + 1; i++) {
        for(int j = 1; j < b.size() + 1; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

            result = max(result, dp[i][j]);
        }
    }

    cout << result << endl;
}