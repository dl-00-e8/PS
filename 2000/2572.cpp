#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, k;
int dp[501][1002];
int card[1001];
vector<pair<int, int>> graph[501];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(card, 0, sizeof(card));
    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        char input;
        cin >> input;
        if(input == 'R') {
            card[i] = 0;
        }
        else if(input == 'G') {
            card[i] = 1; 
        }
        else if(input == 'B') {
            card[i] = 2;
        }
    }
    cin >> m >> k;
    for(int i = 0; i < k; i++) {
        char c;
        int a, b;
        cin >> a >> b >> c;
        if(c == 'R') {
            graph[b].push_back({a, 0});
            graph[a].push_back({b, 0});
        }
        else if(c== 'G') {
            graph[b].push_back({a, 1});
            graph[a].push_back({b, 1});
        }
        else if(c== 'B') {
            graph[b].push_back({a, 2});
            graph[a].push_back({b, 2});
        }
    }

    solve();

    return 0;
}

void solve() {
    for(int i = n; i > 0; i--) {
        for(int j = 1; j < m + 1; j++) {
            for(auto now : graph[j]) {
                // cout << i << " " << j << " " << now.first << " " << now.second << endl;

                if(now.second == card[i]) {
                    dp[j][i] = max(dp[j][i], dp[now.first][i + 1] + 10);
                }
                else {
                    dp[j][i] = max(dp[j][i], dp[now.first][i + 1]);
                }                
            }
        }
    }

    // for(int i = 1; i < m + 1; i++) {
    //     for(int j = 1; j < n + 1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[1][1] << endl;
}

/*
void solve() {
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            for(auto now : graph[j]) {
                // cout << i << " " << j << " " << now.first << " " << now.second << endl;

                if(now.second == card[i]) {
                    dp[j][i] = max(dp[j][i], dp[now.first][i - 1] + 10);
                }
                else {
                    dp[j][i] = max(dp[j][i], dp[now.first][i - 1]);
                }                
            }
        }
    }

    // for(int i = 1; i < m + 1; i++) {
    //     for(int j = 1; j < n + 1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[1][n] << endl;
}
위 방식이 안 되는 이유는 첫 번째 마을에서 첫 번째 카드로 시작을 하여야만 하는데,
해당 방식을 쓰면 첫 번째 마을에서 첫 번째 카드를 시작하는 방식이라고 보장할 수 없음.
*/