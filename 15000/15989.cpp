#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int T;
int dp[10001][4]; // idx1: 만들고자 하는 숫자 / idx: 마지막으로 더하는 숫자 (전제 조건, 덧셈 식을 만들 때는 오름차순으로만 식을 만든다.)
void init();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0, sizeof(dp));

    init();

    cin >> T;
    while(T--) {
        int input;

        cin >> input;
        cout << dp[input][1] + dp[input][2] + dp[input][3] << endl;
    }

    return 0;
}

void init() {
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for(int i = 4; i < 10001; i++) {
        dp[i][1] = dp[i - 1][1]; // i를 만들 때 1로 끝나는 수식을 만들려면, 바로 이전에서 1을 더하는 구조
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2]; // i를 만들 때 2로 끝나는 수식을 만들려면, 바로 이전에서 2를 더하는 구조 (2는 오름 차순 기준 1, 2만 커버 가능)
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]; // i를 만들 때 3로 끝나는 수식을 만들려면, 바로 이전에서 3을 더하는 구조 (3은 오름 차순 기준 1, 2, 3 다 가능)
    }
}