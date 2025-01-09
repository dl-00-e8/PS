#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int N;
int pack[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(pack, 0, sizeof(pack));
    fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(int), INF);

    cin >> N;
    for(int i = 1; i < N + 1; i++) {
        cin >> pack[i];
        dp[i] = pack[i];
    }

    for(int i = 1; i < N + 1; i++) {
        for(int j = 0; j < i + 1; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[N] << endl;

    return 0;
}