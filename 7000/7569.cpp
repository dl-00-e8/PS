#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int m, n, h;
int graph[101][101][101];
int visited[101][101][101];
struct node {
    int x, y, z;

    node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
queue<node> q;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, 0, sizeof(visited));

    cin >> m >> n >> h;
    for(int k = 1; k < h + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                cin >> graph[i][j][k];
                if(graph[i][j][k] == 1) {
                    q.push(node(i, j, k));
                    visited[i][j][k] = -1;
                }
                else if(graph[i][j][k] == -1) {
                    visited[i][j][k] = -1;
                }
            }
        }
    }

    solve();

    return 0;
}

void solve() {
    int result = 0;
    int dx[] = {-1, 1, 0, 0, 0, 0};
    int dy[] = {0, 0, -1, 1, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};

    if(q.empty()) {
        cout << -1 << endl;
        return;
    }

    if(q.size() == m * n * h) {
        cout << 0 << endl;
        return;
    }

    // 토마토 익는 과정
    while(!q.empty()) {
        node now = q.front();
        q.pop();

        result = max(result, visited[now.x][now.y][now.z]);

        for(int i = 0; i < 6; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nz = now.z + dz[i];

            if(1 > nx || nx > n || 1 > ny || ny > m || 1 > nz || nz > h) {
                continue;
            }
            
            if(visited[nx][ny][nz] == 0) {
                if(visited[now.x][now.y][now.z] == -1) {
                    visited[nx][ny][nz] = 1;
                }
                else {
                    visited[nx][ny][nz] = visited[now.x][now.y][now.z] + 1;
                }
                q.push(node(nx, ny, nz));
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            for(int k = 1; k < h + 1; k++) {
                if(graph[i][j][k] == 0) {
                    if(visited[i][j][k] == 0) {
                        cout << -1 << endl;
                        return ;
                    }
                }
            }
        }
    }

    cout << result << endl;
}