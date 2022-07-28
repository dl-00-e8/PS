#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dp[1000001];
int mv[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 0;

    cin >> n;
    for(int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + 1;
        mv[i] = i -1;

        if(i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            mv[i] = i / 2;
        }
        
        if(i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            mv[i] = i / 3;
        }
    }

    cout << dp[n] << endl;
    while(true) {
        cout << n << " ";

        if(n == 1) {
            break;
        }

        n = mv[n];
    }

    return 0;
}