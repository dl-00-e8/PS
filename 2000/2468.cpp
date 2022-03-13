#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, maxNum;
int graph[101][101];
int visited[101][101];
void dfs(int x, int y, int limit, int areaNum);
void solve(int maxNum);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    maxNum = 0;
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            cin >> graph[i][j];
            maxNum = max(maxNum, graph[i][j]);
        }
    }

    solve(maxNum);

    return 0;
}

void dfs(int x, int y, int limit, int areaNum) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = areaNum;
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }

            if(graph[nx][ny] > limit && visited[nx][ny] == 0) {
                visited[nx][ny] = areaNum;
                q.push({nx, ny});   
            }
        }
    }
}

void solve(int maxNum) {
    int result = 0;

    for(int limit = 0; limit < maxNum + 1; limit++) {
        int areaNum = 1;
        
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j ++) {
                if(graph[i][j] > limit && visited[i][j] == 0) {
                    dfs(i, j, limit, areaNum);
                    areaNum++;
                }
            }
        }

        result = max(result, areaNum - 1);
    }

    cout << result << endl;
}