#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int cardNum[1001];
int dp[1001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cardNum, 0, sizeof(cardNum));
    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> cardNum[i];
    }

    solve();

    return 0;
}

void solve() {
    dp[1] = cardNum[1];
    dp[2] = max(cardNum[2], dp[1] + cardNum[1]);
    for(int i = 3; i < n + 1; i++) {
        for(int j = 1; j < i + 1; j++) {
            dp[i] = max(dp[i], dp[i - j] + cardNum[j]);
        }
    }

    cout << dp[n] << endl;
}
