#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int t, l;
int sx, sy, ex, ey;
int graph[301][301];
void bfs(int sx, int sy, int ex, int ey);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        fill(&graph[0][0], &graph[0][0] + sizeof(graph) / sizeof(int), INF);

        cin >> l;
        cin >> sx >> sy;
        cin >> ex >> ey;
    
        bfs(sx, sy, ex, ey);

        // for(int i = 0 ; i < l; i++) {
        //     for(int j = 0; j < l; j++) {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}

void bfs(int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    q.push({sx, sy});
    graph[sx][sy] = 0;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            // 범위 체크
            if(0 > nx || nx >= l || 0 > ny || ny >= l) {
                continue;
            }

            if(graph[nx][ny] > graph[now.first][now.second] + 1) {
                graph[nx][ny] = graph[now.first][now.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << graph[ex][ey] << endl;
}