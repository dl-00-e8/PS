#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int m, n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[501][501];
int dp[501][501];
int dfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[500][501], -1);
    
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << dfs(0, 0) << endl;

    return 0;
}

int dfs(int x, int y) {
    if(x == m - 1 && y == n - 1) {
        return 1;
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }

        if(graph[nx][ny] < graph[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }

    }

    return dp[x][y];
}