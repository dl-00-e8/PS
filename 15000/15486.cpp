#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
pair<int, int> arr[1500001];
ll dp[1500001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    solve();

    return 0;
}

void solve() {
    for(int i = n; i > 0; i--) {
        if(i + arr[i].first > n + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], arr[i].second + dp[i + arr[i].first]);
        }
    }

    cout << dp[1] << endl;
}