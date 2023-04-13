#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char graph[16][16];
bool visited[16][16];
int dfs(int x, int y, int dir);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
        }
    }

    solve();

    return 0;
}

int dfs(int x, int y, int dir) {
    if(x < 1 || x > n || y < 1 || y > m) {
        return 0;
    }
    
    if(graph[x][y] != '#' || visited[x][y]) {
        return 0;
    }

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    return dfs(nx, ny, dir) + 1;
}

void solve() {
    int answer = 1;

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(graph[i][j] == '#' && !visited[i][j]) {
                int len1 = 20;

                // 십자가 팔 길이 구하기
                for(int d = 0; d < 4; d++) {
                    len1 = min(len1, dfs(i, j, d));
                }

                for(int l = 1; l < len1 + 1; l++) {
                    // 방문 처리
                    for(int d = 0; d < 4; d++) {
                        for(int k = 1; k < l; k++) {
                            int nx = i + k * dx[d];
                            int ny = j + k * dy[d];

                            visited[nx][ny] = true;
                        }
                    }

                    for(int x = 1; x < n + 1; x++) {
                        for(int y = 1; y < m + 1; y++) {
                            if(graph[x][y] == '#' && !visited[x][y]) {
                                int len2 = 20;
                                
                                // 십자가 팔 길이 구하기
                                for(int d = 0; d < 4; d++) {
                                    len2 = min(len2, dfs(x, y, d));
                                }
                                
                                answer = max(answer,  (1 + 4 * (l - 1)) * (1 + 4 * (len2 - 1)));
                            }
                        }
                    }

                    // 방문 복귀
                    for(int d = 0; d < 4; d++) {
                        for(int k = 1; k < l; k++) {
                            int nx = i + k * dx[d];
                            int ny = j + k * dy[d];

                            visited[nx][ny] = false;
                        }
                    }
                }
            }
        }
    }



    cout << answer << endl;
}