#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
pair<int, int> start;
int graph[1001][1001];
int visited[1001][1001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, -1, sizeof(visited));

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 0) {
                visited[i][j] = 0;
            }
            if(graph[i][j] == 2) {
                start.first = i;
                start.second = j;
            }
        }
    }

    solve();
}

void solve() {
    queue<pair<int, int> > q;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    q.push(start);
    visited[start.first][start.second] = 0;
    while(!q.empty()) {
        pair<int, int> now = q.front();

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            if(graph[nx][ny] != 0 && visited[nx][ny] == -1) {
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }

    }


    // Output
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}