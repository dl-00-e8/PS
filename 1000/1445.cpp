#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
pair<int, int> start;
pair<int, int> dest;
int trCnt[51][51]; // 쓰레기 카운트
int nearCnt[51][51]; // 쓰레기 주변 카운트
char graph[51][51];
vector<pair<int, int>> trash;
void dijkstra(int sx, int sy);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    fill(&trCnt[0][0], &trCnt[0][0] + sizeof(trCnt) / sizeof(int), INF);
    fill(&nearCnt[0][0], &nearCnt[0][0] + sizeof(nearCnt) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
            else if(graph[i][j] == 'F') {
                dest.first = i;
                dest.second = j;
            }
            else if(graph[i][j] == 'g') {
                trash.push_back({i, j});
            }
        }
    }

    dijkstra(start.first, start.second);
    
    return 0;
}

void dijkstra(int sx, int sy) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;

    // trash 주변 node 정보 update
    for(int i = 0; i < trash.size(); i++) {
        for(int j = 0; j < 4; j++) {
            int nx = trash[i].first + dx[j];
            int ny = trash[i].second + dy[j];

            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            
            if(graph[nx][ny] == '.') {
                graph[nx][ny] = 'N';
            }
        }
    }

    // dijkstra 진행
    trCnt[sx][sy] = 0;
    nearCnt[sx][sy] = 0;
    pq.push({{0, 0}, {sx, sy}});
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int tr = pq.top().first.first;
        int near = pq.top().first.second;

        pq.pop();

        // 최단거리 아닌 경우
        if(tr > trCnt[x][y]) {
            continue;
        }
        if(tr == trCnt[x][y] && near > nearCnt[x][y]) {
            continue;
        }

        // 주변 탐색
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 탈출 조건
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            if(graph[nx][ny] == '.' || graph[nx][ny] == 'S' || graph[nx][ny] == 'F') {
                if(trCnt[nx][ny] > tr) {
                    trCnt[nx][ny] = tr;
                    nearCnt[nx][ny] = near;
                    pq.push({{trCnt[nx][ny], nearCnt[nx][ny]}, {nx, ny}});
                }
                else if(trCnt[nx][ny] == tr && nearCnt[nx][ny] > near) {
                    nearCnt[nx][ny] = near;
                    pq.push({{trCnt[nx][ny], nearCnt[nx][ny]}, {nx, ny}});
                }
            }
            else if(graph[nx][ny] == 'g') {
                if(trCnt[nx][ny] > tr + 1) {
                    trCnt[nx][ny] = tr + 1;
                    nearCnt[nx][ny] = near;
                    pq.push({{trCnt[nx][ny], nearCnt[nx][ny]}, {nx, ny}});
                }
                else if(trCnt[nx][ny] == tr + 1 && nearCnt[nx][ny] > near) {
                    nearCnt[nx][ny] = near;
                    pq.push({{trCnt[nx][ny], nearCnt[nx][ny]}, {nx, ny}});
                }
            }
            else if(graph[nx][ny] == 'N') {
                if(trCnt[nx][ny] > tr) {
                    trCnt[nx][ny] = tr;
                    nearCnt[nx][ny] = near + 1;
                    pq.push({{trCnt[nx][ny], nearCnt[nx][ny]}, {nx, ny}});
                }
                else if(trCnt[nx][ny] == tr && nearCnt[nx][ny] > near + 1) {
                    nearCnt[nx][ny] = near + 1;
                    pq.push({{trCnt[nx][ny], nearCnt[nx][ny]}, {nx, ny}});
                }
            }
        }
    }

    cout << trCnt[dest.first][dest.second] << " " << nearCnt[dest.first][dest.second] << endl;
}