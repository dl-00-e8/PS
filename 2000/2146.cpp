#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, areaNum;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[101][101];
int dist[101][101];
int area[101][101];
set<pair<int, int>> s[10001];
void dfs(int x, int y, int areaNum);
int bfs(int node);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(area, 0, sizeof(area));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            cin >> graph[i][j];
        }
    }

    solve();

    return 0;
}

void dfs(int x, int y, int areaNum) {
    for(int i =  0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny < 1 || ny > n) {
            continue;
        }

        if(graph[nx][ny] == 0) {
            s[areaNum].insert({x, y});
        }

        if(graph[nx][ny] == 1 && !area[nx][ny]) {
            area[nx][ny] = areaNum;
            dfs(nx, ny, areaNum);
        }
    }
}

int bfs(int node) {
    int result = INF;
    queue<pair<int, int>> q;
    
    //insert queue
    for(auto iter = s[node].begin(); iter != s[node].end(); iter++) {
        q.push({iter->first, iter->second});
        dist[iter->first][iter->second] = 0;
    }
    
    // Bfs Algorithm
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }

            if(dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                if(area[nx][ny] != node && area[nx][ny] != 0)  {
                    result = min(result, dist[x][y]);
                    q.push({nx, ny});
                }
                else if(area[nx][ny] == node) {
                    continue;
                }
                else if(area[nx][ny] == 0) {
                    q.push({nx, ny});
                }
            }
        }
    }

    return result;
}

void solve() {
    // Area Check
    areaNum = 1;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(!area[i][j] && graph[i][j] == 1) {
                area[i][j] = areaNum;
                dfs(i, j, areaNum);
                areaNum++;
            }
        }
    }

    // Solution with BFS
    int answer = INF;
    for(int i = 1; i < areaNum; i++) {
        // Default Setting
        fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), INF);

        int temp = bfs(i);

        answer = min(answer, temp);
    }

    cout << answer << endl;
}
