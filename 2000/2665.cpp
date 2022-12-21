#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
int graph[51][51];
int visited[51][51];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(int), INF);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            char input;
            cin >> input;

            if(input == '1') {
                graph[i][j] = 1;
            }
            else {
                graph[i][j] = 0;
            }         
        }
    }

    solve();

    return 0;
}

void solve() {
    queue<pair<int, int>> q;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    q.push({1, 1});
    visited[1][1] = 0;
    while(!q.empty()) {
        pair<int, int > now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(1 > nx || n < nx || 1 > ny || n < ny) {
                continue;
            }

            if(graph[nx][ny] == 0) {
                if(visited[nx][ny] > visited[now.first][now.second] + 1) {
                    visited[nx][ny] = visited[now.first][now.second] + 1;
                    q.push({nx, ny});
                }
            }
            else {
                if(visited[nx][ny] > visited[now.first][now.second]) {
                    visited[nx][ny] = visited[now.first][now.second];
                    q.push({nx, ny});
                }
            }
        }   
    }

    // for(int i = 1; i < n + 1; i++) {
    //     for(int j = 1; j < n + 1; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << visited[n][n] << endl;
}