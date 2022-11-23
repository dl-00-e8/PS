#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m, k;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[3001][3001];
int visited[3001][3001];
void trafficDfs(int x, int y, int cnt);
void bfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&graph[0][0], &graph[0][0] + sizeof(graph) / sizeof(int), INF);
    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int r, c, d;
        cin >> r >> c >> d;

        trafficDfs(r, c, d);
    }

    // for(int i = 1; i < n + 1; i++) {
    //     for(int j = 1; j < m + 1; j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(graph[1][1] == -1 || graph[n][m] == -1) {
        cout << "NO" << endl;
    }
    else {
        bfs(1, 1);
    }
    
    // for(int i = 1; i < n + 1; i++) {
    //     for(int j = 1; j < m + 1; j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

void trafficDfs(int x, int y, int cnt) {
    graph[x][y] = -1;
    
    if(cnt == 0) {
        return ;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        } 

        if(graph[nx][ny] == INF) {
            trafficDfs(nx, ny, cnt - 1);
        }
    }


}

void bfs(int x, int y) {
    queue<pair<int, int>> q;

    q.push({x, y});
    graph[x][y] = 0;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            } 

            if(graph[nx][ny] != -1 && !visited[nx][ny]) {
                if(graph[nx][ny] > graph[now.first][now.second] + 1) {
                    graph[nx][ny] = graph[now.first][now.second] + 1;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    if(graph[n][m] != INF && graph[n][m] == -1) {
        cout << "YES" << endl << graph[n][m] << endl;
    }
    else {
        cout << "NO" << endl;
    }
}