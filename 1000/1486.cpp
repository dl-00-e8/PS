#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m, t, D;
int graph[26][26];
int dist[26][26];
int dist2[26][26];
void dijkstra(int sx, int sy);
void dijkstra2(int sx, int sy);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), INF);
    fill(&dist2[0][0], &dist2[0][0] + sizeof(dist2) / sizeof(int), INF);

    // input
    cin >> n >> m >> t >> D;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            char input;
            cin >> input;
            if('A' <= input && input <= 'Z') {
                graph[i][j] = input - 'A';
            }
            else if('a' <= input && input <= 'z') {
                graph[i][j] = 26 + (input - 'a');
            }   
        }
    }

    // solve
    solve();

    return 0;
}

void dijkstra(int sx, int sy) {
    int result = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {sx, sy}});
    dist[sx][sy] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        // 진행하지 않아도 되는 경우
        if(cost > dist[x][y]) {
            continue;
        }


        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 조건문
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            // 높이 차이가 T보다 크지 않아야 함
            if(abs(graph[nx][ny] - graph[x][y]) > t) {
                continue;
            }

            int d;
            if(graph[x][y] >= graph[nx][ny]) {
                d = 1;
            }
            else {
                d = pow(graph[nx][ny] - graph[x][y] , 2);
            }

            if(dist[nx][ny] > dist[x][y] + d && dist[x][y] + d) {
                dist[nx][ny] = dist[x][y] + d;
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
}

void dijkstra2(int sx, int sy) {
    int result = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {sx, sy}});
    dist2[sx][sy] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        // 진행하지 않아도 되는 경우
        if(cost > dist2[x][y]) {
            continue;
        }


        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 조건문
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }

            // 높이 차이가 T보다 크지 않아야 함
            if(abs(graph[nx][ny] - graph[x][y]) > t) {
                continue;
            }

            int d;
            if(graph[x][y] <= graph[nx][ny]) {
                d = 1;
            }
            else {
                d = pow(graph[nx][ny] - graph[x][y] , 2);
            }

            if(dist2[nx][ny] > dist2[x][y] + d && dist2[x][y] + d) {
                dist2[nx][ny] = dist2[x][y] + d;
                pq.push({dist2[nx][ny], {nx, ny}});
            }
        }
    }
}

void solve() {
    int result = 0;

    dijkstra(1, 1);
    dijkstra2(1, 1);

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(dist[i][j] + dist2[i][j] <= D) {
                result = max(result, graph[i][j]);
            }
        }
    }

    cout << result << endl;
}