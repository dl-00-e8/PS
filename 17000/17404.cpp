#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
int house[1001][3];
int dp[1001][3]; // 0 : red, 1 : green, 2 : blue
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }

    solve();

    return 0;
}

void solve() {
    int result = INF;

    for(int c = 0; c < 3; c++) {
        // 1번 집 color 정하기 (나머지는 INF 초기화)
        for(int i = 0; i < 3; i++) {
            dp[1][i] = INF;
        }
        dp[1][c] = house[1][c];

        for(int i = 2; i < n + 1; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
        }
        
        for(int i = 0; i < 3; i++) {
            // 첫 번째 집과 마지막 집의 색이 같은 경우
            if(i == c) {
                continue;
            }

            result = min(result, dp[n][i]);
        }
    }

    cout << result << endl;
}