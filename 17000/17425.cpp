#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int t, n;
ll dp[1000001];
ll preSum[1000001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    memset(preSum, 0, sizeof(preSum));

    solve();

    cin >> t;
    while(t--) {
        cin >> n; 

        cout << preSum[n] << endl;
    }
    
    return 0;
}

void solve() {
    for(int i = 1; i < 1000001; i++) {
        for(int j = i; j < 1000001; j += i) {
            dp[j] += i;
        }
    }

    for(int i = 1; i < 1000001; i++) {
        preSum[i] = preSum[i - 1] + dp[i];
    }
}