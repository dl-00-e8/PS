#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m, t;
pair<int, int> gram;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[101][101];
int visited[101][101];
int bfs(int x, int y); // ±×¶÷ È¹µæ X && °øÁÖ ±¸ÇÏ±â
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 2) {
                gram.first = i;
                gram.second = j;
            }
        }
    }

    solve();

    return 0;
}

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    
    fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(int), INF);

    q.push({x, y});
    visited[x][y] = 0;
    while(!q.empty()) {
        pair<int, int> now = q.front();

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            if(graph[nx][ny] != 1 && visited[nx][ny] == INF) {
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    return visited[n][m];
}

void solve() {
    int answer = bfs(1, 1);
    
    answer = min(answer, visited[gram.first][gram.second] + abs(n - gram.first) + abs(m - gram.second));

    if(answer <= t) {
        cout << answer << endl;
    }
    else {
        cout << "Fail" << endl;
    }
}