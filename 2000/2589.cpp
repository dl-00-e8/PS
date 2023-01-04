#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int l, w;
int graph[51][51];
int visited[51][51];
int bfs(int x, int y);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> l >> w;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < w; j++) {
            char input;
            cin >> input;

            if(input == 'W') {
                graph[i][j] = 0;
            }
            else if(input == 'L') {
                graph[i][j] = 1;
            }
        }
    }

    solve();

    return 0;
}

int bfs(int x, int y) {
    int result = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = 0;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(0 > nx || nx >= l || 0 > ny || ny >= w) {
                continue;
            }

            if(graph[nx][ny] == 1 && visited[nx][ny] > visited[now.first][now.second] + 1) {
                visited[nx][ny] = visited[now.first][now.second] + 1;
                result = max(result, visited[nx][ny]);
                q.push({nx, ny});
            }
        }
    }

    return result;
}

void solve() {
    // Brute Force + bfs Algorithm
    int answer = 0;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < w; j++) {
            if(graph[i][j] == 1) {
                fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(int), INF);
                
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer << endl;
}