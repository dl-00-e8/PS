#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX_INT 987654321

int solve(int N, string input);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string input;

    cin >> N >> input;
    cout << solve(N, input);

    return 0;
}

int solve(int N, string input) {
    int dp[1001][3]; // 0: B, 1: O, 2: J
    vector<int> load_idx[3];

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), MAX_INT);

    for(int i = 0; i < input.size(); i++) {
        if(input[i] == 'B') {
            load_idx[0].push_back(i + 1);
        } else if(input[i] == 'O') {
            load_idx[1].push_back(i + 1);
        } else if(input[i] == 'J') {
            load_idx[2].push_back(i + 1);
        }
    }

    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[1][2] = 0;
    for(int i = 1; i < N + 1; i++) {
        // B
        if(dp[i][0] != MAX_INT && input[i - 1] == 'B') {
            for(auto j: load_idx[1]) {
                if(dp[i][0] + (j - i)*(j - i) < dp[j][1]) {
                    dp[j][1] = dp[i][0] + (j - i)*(j - i);
                }
            }
        }

        // O
        if(dp[i][1] != MAX_INT && input[i - 1] == 'O') {
            for(auto j: load_idx[2]) {
                if(dp[i][1] + (j - i)*(j - i) < dp[j][2]) {
                    dp[j][2] = dp[i][1] + (j - i)*(j - i);
                }
            }  
        }

        // J
        if(dp[i][2] != MAX_INT && input[i - 1] == 'J') {
            for(auto j: load_idx[0]) {
                if(dp[i][2] + (j - i)*(j - i) < dp[j][0]) {
                    dp[j][0] = dp[i][2] + (j - i)*(j - i);
                }
            }
        }
    }

    // 도달하지 못 했을 경우
    if(dp[N][0] == MAX_INT && dp[N][1] == MAX_INT && dp[N][2] == MAX_INT) {
        return -1;
    }
    return min(dp[N][0], min(dp[N][1], dp[N][2]));
}