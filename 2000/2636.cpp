#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, cheese;
int graph[101][101];
int graphCopy[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int sx, int sy);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cheese = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 1) {
                cheese++;
            }
        }
    }

    solve();

    return 0;
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    bool visited[101][101];

    memset(visited, 0, sizeof(visited));

    q.push({sx, sy});
    visited[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) {
                continue;
            }

            if(graph[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
            else if(graph[nx][ny] == 1 && !visited[nx][ny]) {
                graphCopy[nx][ny] = 0;
                visited[nx][ny] = true;
                cheese--;
            }
        }

    }
}

void solve() {
    int t, size;

    t = 0;
    size = 0;
    while(cheese) {
        size = cheese;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                graphCopy[i][j] = graph[i][j];
            }
        }

        bfs(0, 0);

        t++;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                graph[i][j] = graphCopy[i][j];
            }
        }
    }

    cout << t << endl << size << endl;
}