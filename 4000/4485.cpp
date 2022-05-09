#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int idx, n;
int graph[126][126];
int dist[126][126];
int dijkstra(int sx, int sy);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    idx = 0;
    while(++idx) {
        cin >> n;

        if(n == 0) {
            break;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        fill(&dist[0][0], &dist[125][126], INF);
        cout << "Problem " << idx << ": " << dijkstra(0, 0) << endl;
    }

    return 0;
}

int dijkstra(int sx, int sy) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({sx, sy});
    dist[sx][sy] = graph[sx][sy];

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }

            if(dist[nx][ny] > dist[x][y] + graph[nx][ny]) {
                dist[nx][ny] = dist[x][y] + graph[nx][ny];
                q.push({nx, ny});
            }
        }
    }

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */

    return dist[n - 1][n - 1];
}