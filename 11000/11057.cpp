#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, result;
int dp[1001][10]; // 1001 : 자릿수, 10 : 해당 자리수의 0~9숫자
int preSum[1001][10]; // 각 자릿수별 누적합

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(preSum, 0, sizeof(preSum));
    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i < 1001; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == 1) {
                dp[i][j] = 1;
                continue;
            }
            for(int k = 0; k < j + 1; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int result = 0;
    for(int i = 0; i < 10; i++) {
        result += dp[n][i];
    }

    cout << result % 10007 << endl;

    return 0;
}