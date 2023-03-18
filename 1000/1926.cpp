#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int graph[501][501];
int visited[501][501];
int bfs(int x, int y);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
        }
    }

    solve();
}

int bfs(int x, int y) {
    int result = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        pair<int, int> now = q.front();

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            if(graph[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                result++;
            }
        }
    }

    return result;
}

void solve() {
    int paintCnt = 0;
    int answer = 0;

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(graph[i][j] == 1 && !visited[i][j]) {
                answer = max(answer, bfs(i, j));
                paintCnt++;
            }
        }
    }

    cout << paintCnt << endl << answer << endl;
}