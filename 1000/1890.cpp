#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int N;
int graph[101][101];
ll dp[101][101];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(dp, 0, sizeof(dp));

    cin >> N;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < N + 1; j++) {
            cin >> graph[i][j];
        }
    }
    
    solve();
    cout << dp[N][N] << endl;

    return 0;
}

void solve() {
    int dx[] = {1, 0};
    int dy[] = {0, 1};
    dp[1][1] = 1;

    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < N + 1; j++) {
            if(i == N && j == N) {
                continue;
            }
            for(int d = 0; d < 2; d++) {
                int nx = i + (graph[i][j] * dx[d]);
                int ny = j + (graph[i][j] * dy[d]);

                if(nx < 1 || nx > N || ny < 1 || ny > N) {
                    continue;
                }

                dp[nx][ny] += dp[i][j];
            }
        }
    }
}