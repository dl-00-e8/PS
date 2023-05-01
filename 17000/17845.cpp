#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k;
int important[1001];
int study_time[1001];
int dp[1001][10001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n >> k;
    for(int i = 1; i < k + 1; i++) {
        cin >> important[i] >> study_time[i];
    }

    solve();

    return 0;
}

void solve() {
    int answer = 0;

    for(int i = 1; i < k + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            int temp = 0;
            if(study_time[i] <= j) {
                temp = dp[i - 1][j - study_time[i]] + important[i];
            }
            dp[i][j] = max(dp[i - 1][j], temp); 
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << endl;
}