#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 100000

int N, answer;
int dp[MAX + 1][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> N;
    for(int i = 1; i < N + 1; i++) {
        char input;

        cin >> input;

        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];

        switch (input) {
            case 'P':
                dp[i][0]++;
                break;
            
            case 'H':
                dp[i][1]++;
                break;

            case 'S':
                dp[i][2]++;
                break;
        }
    }
    
    answer = 0;
    int result = 0, idx = 0;
    for(int i = 1; i < N + 1; i++) {
        if(result < dp[i][0]) {
            result = dp[i][0];
            idx = i;
        }

        if(result < dp[i][1]) {
            result = dp[i][1];
            idx = i;
        }

        if(result < dp[i][2]) {
            result = dp[i][2];
            idx = i;
        }

        int temp = max((dp[N][0] - dp[idx][0]), max((dp[N][1] - dp[idx][1]), (dp[N][2] - dp[idx][2])));

        answer = max(answer, result + temp);
    }

    cout << answer << endl;

    return 0;
}
