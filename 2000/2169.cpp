#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF -100000001

int n, m;
int dx[] = {1, 0, 0}; // 위쪽으로 이동 불가
int dy[] = {0, -1, 1}; // 위쪽으로 이동 불가
int graph[1001][1001];
bool visited[1001][1001];
int dp[1001][1001][3];
int dfs(int x, int y, int dir);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
        }
    }

    cout << dfs(1, 1, 0) << endl;

    return 0;
}

int dfs(int x, int y, int dir) {
    if(x == n && y == m) {
        return dp[x][y][dir] = graph[x][y];
    }

    if(dp[x][y][dir] != INF) {
        return dp[x][y][dir];
    }

    visited[x][y] = true;
    
    int tempMax = INF;
    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }

        if(!visited[nx][ny]) {
            tempMax = max(tempMax, dfs(nx, ny, i));
        }
    }

    visited[x][y] = false;

    return dp[x][y][dir] = graph[x][y] + tempMax;
}


/* 
문제에서 헤맨 포인트
1. dp배열을 dp[1001][1001][3];으로 선언하여 3방향에 대한 별도처리를 진행해야 함.
그러나, dp[1001][1001]로 해결하고자 하였음.

2. 결국 DFS를 통해 들어가서 dp배열은 dp[n][m][?]부터 시작되는 것임.
DFS + DP의 정확한 작동 원리에 대한 이해도가 떨어지는 듯함.
DP유형에 대한 실력 부족
*/