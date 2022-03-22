#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int graph[1001][1001];
int visited[1001][1001][2];
void bfs(int x, int y);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        string input;
        cin >> input;
        for(int j = 1; j < m + 1; j++) {
            if(input[j - 1] == '1') {
                graph[i][j] = 1;
            }
            else if(input[j - 1] == '0') {
                graph[i][j] = 0;
            }
        }
    }

    solve();

    return 0;
}

void bfs(int x, int y) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {x, y}});
    visited[x][y][0] = 1;
    while(!q.empty()) {
        int cost = q.front().first;
        pair<int, int> now = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(1 > nx || nx > n || 1 > ny || ny > m) {
                continue;
            }

            // 이미 벽을 한 번 부쉈을 경우, + 앞에 또 벽일 경우,
            if(graph[nx][ny] == 1) {
                if(cost == 1) {
                    continue;
                }
                else if(cost == 0) {
                    if(visited[nx][ny][cost + 1] > visited[now.first][now.second][cost] + 1) {
                    visited[nx][ny][cost + 1] = visited[now.first][now.second][cost] + 1;
                    q.push({1, {nx, ny}});
                }
                }
            }
            else if(graph[nx][ny] == 0 && visited[nx][ny][cost] > visited[now.first][now.second][cost] + 1) {
                visited[nx][ny][cost] = visited[now.first][now.second][cost] + 1;
                q.push({cost, {nx, ny}});
            }
        
        }

    }
}

void solve() {
    fill(&visited[0][0][0], &visited[1000][1001][2], INF);

    bfs(1, 1);

    /*
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    */

    if(visited[n][m][0] == INF && visited[n][m][1] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << min(visited[n][m][0], visited[n][m][1]) << endl;
    }
}