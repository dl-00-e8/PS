#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
ll dp[1000001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;

    solve();
    
    ll result = 0;
    for(int i = 1; i < n + 1; i++) {
        result += dp[i];
    }
    cout << result << endl;

    return 0;
}

void solve() {
    for(int i = 1; i < 1000001; i++) {
        for(int j = i; j < 1000001; j += i) {
            dp[j] += i;
        }   
    }
}