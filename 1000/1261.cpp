#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int graph[101][101];
int dist[101][101];
int dijkstra(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for(int i = 1; i < n + 1; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < m; j++) {
            if(input[j] == '1') {
                graph[i][j + 1] = 1;
            }
            else if(input[j] == '0') {
                graph[i][j + 1] = 0;
            }
        }
    }

    cout << dijkstra(1, 1) << endl;


    return 0;
}

int dijkstra(int x, int y) {
    int result = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    fill(&dist[0][0], &dist[100][101], INF);

    pq.push({0, {x, y}});
    dist[x][y] = 0;
    while(!pq.empty()) {
        pair<int, pair<int, int>> now = pq.top();
        pq.pop();

        if(now.second.first == n && now.second.second == m) {
            result = now.first;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nx = now.second.first + dx[i];
            int ny = now.second.second + dy[i];

            if(1 > nx || nx > n || 1 > ny || ny > m) {
                continue;
            }

            if(graph[nx][ny] == 0 && dist[nx][ny] > now.first) {
                dist[nx][ny] = now.first;
                pq.push({now.first, {nx, ny}});
            }
            else if(graph[nx][ny] == 1 && dist[nx][ny] > now.first + 1) {
                dist[nx][ny] = now.first + 1;
                pq.push({now.first + 1, {nx, ny}});
            }
        }
    }

    return result;
}

/*
greater : 오름차순
less : 내림차순
*/