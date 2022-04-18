#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, areaNum;
int graph[101][101];
int area[101][101];
void bfs(int sx, int sy, int num);
void rgBfs(int sx, int sy, int num);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char input;
            cin >> input;
            
            if(input == 'R') {
                graph[i][j] = 0;
            }
            else if(input == 'G') {
                graph[i][j] = 1;
            }
            else if(input == 'B') {
                graph[i][j] = 2;
            }
        }
    }

    solve();

    return 0;
}

void bfs(int sx, int sy, int num) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({sx, sy});
    area[sx][sy] = num;
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

            if(graph[x][y] == graph[nx][ny] && area[nx][ny] == -1) {
                area[nx][ny] = area[x][y];
                q.push({nx, ny});
            }

        }
    }
}

void rgBfs(int sx, int sy, int num) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    q.push({sx, sy});
    area[sx][sy] = num;
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

            if(graph[x][y] == 0 || graph[x][y] == 1) {
                if(area[nx][ny] == -1 && (graph[nx][ny] == 0 || graph[nx][ny] == 1)) {
                    area[nx][ny] = area[x][y];
                    q.push({nx, ny});
                }
            }
            else {
                if(graph[x][y] == graph[nx][ny] && area[nx][ny] == -1) {
                    area[nx][ny] = area[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }
}

void solve() {
    int now;

    // 적록색약 X
    areaNum = 0;
    fill(&area[0][0], &area[100][101], -1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(area[i][j] == -1) {
                bfs(i, j, areaNum);
                areaNum++;
            }
        }
    }

    cout << areaNum << " ";

    // 적록색약 O
    areaNum = 0;
    fill(&area[0][0], &area[100][101], -1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(area[i][j] == -1) {
                rgBfs(i, j, areaNum);
                areaNum++;
            }
        }
    }

    cout << areaNum << endl;
}