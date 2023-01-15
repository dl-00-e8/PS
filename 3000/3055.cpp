#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int r, c;
pair<int, int> start;
pair<int, int> dest;
queue<pair<int, pair<int, int>>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char graph[51][51];
int visited[51][51];
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    cin >> r >> c;
    for(int i = 1; i < r + 1; i++) {
        for(int j = 1; j < c + 1; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 'D') {
                dest.first = i;
                dest.second = j;
            }
            else if(graph[i][j] == 'S') {
                start.first = i;
                start.second = j;
                visited[i][j] = 1;
            }
            else if(graph[i][j] == '*') {
                q.push({-1, {i, j}});
            }
        }
    }
    q.push({0, start});

    bfs();

    return 0;
}

void bfs() {
    while(!q.empty()) {
        int type = q.front().first;
        int x = q.front().second.first;
        int y=  q.front().second.second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > r || ny < 1 || ny > c) {
                continue;
            }

            if(type == -1) {
                if(graph[nx][ny] == '.' || graph[nx][ny] == 'S') {
                    graph[nx][ny] = '*';
                    q.push({-1, {nx, ny}});
                }
            }
            else if(type == 0) {
                if(graph[nx][ny] == '.' || graph[nx][ny] == 'D') {
                    if(!visited[nx][ny]) {
                        visited[nx][ny] = visited[x][y] + 1;
                        q.push({0, {nx, ny}});
                    }
                }
            }
        }
    }

    if(visited[dest.first][dest.second] != 0) {
        cout << visited[dest.first][dest.second] - 1<< endl;
    }
    else {
        cout << "KAKTUS" << endl;
    }
}