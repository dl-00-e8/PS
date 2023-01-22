#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
int dp[51];
int fibonacci(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(int), INF);

    cin >> n;

    cout << fibonacci(n) << endl;

    // for(int i = 0; i < n + 1; i++) {
    //     cout << dp[i] << " ";
    // }

    return 0;
}

int fibonacci(int x) {
    if(x == 1) {
        return dp[1] = 1;
    }
    else if(x == 0) {
        return dp[0] = 1;
    }

    if(dp[x] != INF) {
        return dp[x] % 1000000007;
    }

    return dp[x] = (fibonacci(x - 2) + fibonacci(x - 1) + 1)  % 1000000007;
}