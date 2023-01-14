#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int graph[1001][1001];
int visited[1001][1001];
void bfs(int x, int y, int areaNum);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    solve();

    return 0;
}

void bfs(int x, int y, int areaNum) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = areaNum;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx == -1) {
                if(ny == -1) {
                    nx = n - 1;
                    ny = m - 1;
                }
                else if(ny == m) {
                    nx = n - 1;
                    ny = 0;
                }
                else {
                    nx = n - 1;
                }
            }
            else if(nx == n) {
                if(ny == -1) {
                    nx = 0;
                    ny = m - 1;
                }
                else if(ny == m) {
                    nx = 0;
                    ny = 0;
                }
                else {
                    nx = 0;
                }
            }
            else {
                if(ny == -1) {
                    ny = m - 1;
                }
                else if(ny == m) {
                    ny = 0;
                }
                else {

                }
            }

            if(!visited[nx][ny] && graph[nx][ny] == 0) {
                visited[nx][ny] = areaNum;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    int areaNum = 1;

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0 && graph[i][j] == 0) {
                bfs(i, j, areaNum);
                areaNum++;
            }
        }
    }

    cout << areaNum - 1 << endl;
}
