#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int graph[101][101];
bool visited[101][101];
int bfs(int x, int y, int type);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char input;
            cin >> input;

            if(input == 'W') {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = 1;
            }
        }
    }

    solve();

    return 0;
}

int bfs(int x, int y, int type) {
    int cnt = 0;    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;
    cnt++;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if(graph[nx][ny] == type && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    return cnt;
}

void solve() {
    int blueCnt = 0;
    int whiteCnt = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                int temp = bfs(i, j, graph[i][j]);

                if(graph[i][j] == 0) {
                    whiteCnt += pow(temp, 2);
                }
                else if(graph[i][j] == 1) {
                    blueCnt += pow(temp, 2);
                }

                // cout << i << " " << j << " " << temp << endl;
            }
        }
    }

    cout << whiteCnt << " " << blueCnt << endl;
}