#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[301][301];
int graphCopy[301][301];
int visited[301][301];
void dfs(int x, int y, int areaNum);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
            
            if(graph[i][j] != 0) {
                q.push({i, j});
            }
        }
    }

    solve();
    
    return 0;
}

void dfs(int x, int y, int areaNum) {
    visited[x][y] = areaNum;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }

        if(graph[nx][ny] != 0 && visited[nx][ny] == 0) {
            dfs(nx, ny, areaNum);
        }
    }
}

void solve() {
    int t = 0;
    int size, areaNum;
    bool divide = false;

    // 빙산이 다 녹아 없어질 때까지
    while(!q.empty()) {
        // graphCopy
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                graphCopy[i][j] = graph[i][j];
            }
        }
        // 빙산이 녹는 과정
        size = q.size();
        for(int i = 0; i < size; i++) {
            int cnt = 0;
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }

                if(graph[nx][ny] == 0) {
                    cnt++;
                }
            }

            // 빙산이 녹게 될 경우
            if(graph[x][y] - cnt <= 0) {
                graphCopy[x][y] = 0;
            }
            else {
                graphCopy[x][y] -= cnt;
                q.push({x, y});
            }
        }
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                graph[i][j] = graphCopy[i][j];
            }
        }

        t++;

        // 빙산 분리 여부 확인 (using dfs)
        memset(visited, 0, sizeof(visited));
        size = q.size();
        areaNum = 1;
        for(int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(!visited[x][y] && areaNum == 1) {
                dfs(x, y, areaNum);
                areaNum++;
            }
            else if(!visited[x][y] && areaNum > 1) {
                divide = true;
                break;
            }

            q.push({x, y});
        }

        // 빙산이 분리되었다면
        if(divide) {
            break;
        }
    }   
    
    // Output
    if(divide) {
        cout << t << endl;
    }
    else {
        cout << 0 << endl;
    }
    
}