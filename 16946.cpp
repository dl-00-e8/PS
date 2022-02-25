#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, num;
vector<pair<int, int>> wall;
vector<pair<int, int>> space;
int graph[1001][1001];
int result[1001][1001];
int areaNum[1001][1001];
bool visited[1001][1001];
vector<int> areaSize;
void wallBfs(pair<int, int> now); // 1인 곳에서 bfs 결과 반환
void spaceBfs(pair<int, int> now); //0인 곳에서 bfs 결과 반환
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char input;
            cin >> input;
            if(input == '1') {
                wall.push_back({i, j});
                graph[i][j] = 1;
            }
            else if(input == '0') {
                space.push_back({i, j});
                graph[i][j] = 0;
            }
        }
    }

    memset(areaNum, -1, sizeof(areaNum));

    solve();

    return 0;
}

void wallBfs(pair<int, int> now) {
    int nx, ny;
    set<int> search;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for(int i = 0; i < 4; i++) {
        nx = now.first + dx[i];
        ny = now.second + dy[i];

        if(0 > nx || nx >= n || 0 > ny || ny >= m) {
                continue;
        }

        if(graph[nx][ny] == 0) {
            if(search.find(areaNum[nx][ny]) == search.end()) {
                search.insert(areaNum[nx][ny]);
                result[now.first][now.second] += areaSize[areaNum[nx][ny]];
            }
        }
    }

    result[now.first][now.second]++;
    result[now.first][now.second] %= 10;
}

void spaceBfs(pair<int, int> now) {
    int x, y, nx, ny, cnt;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<pair<int, int>> q;

    cnt = 1;
    q.push(now);
    visited[now.first][now.second] = true;
    areaNum[now.first][now.second] = num;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if(0 > nx || nx >= n || 0 > ny || ny >= m) {
                continue;
            }

            if(graph[nx][ny] == 0 && visited[nx][ny] == false) {
                cnt++;
                q.push({nx, ny});
                areaNum[nx][ny] = num;
                visited[nx][ny] = true;               
            }
        }
    }

    areaSize.push_back(cnt);
}

void solve() {
    num = 0;
    // 0인 곳에서 움직일 수 있는 경우의 수 계산
    for(int i = 0; i < space.size(); i++) {
        if(visited[space[i].first][space[i].second] == false) {
            spaceBfs(space[i]);
            num++;
        }
    }

    // 1인 곳에서 1을 없애고 진행할 때 경우의 수 계산하여 result 배열에 저장
    for(int i = 0; i < wall.size(); i++) {
        wallBfs(wall[i]);
    }

    // 출력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}