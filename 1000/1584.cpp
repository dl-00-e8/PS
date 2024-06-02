#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 987654321

int N, M;
int graph[502][502];
bool visited[502][502];
int dist[502][502];
int solve(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), MAX);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;

        // 입력받은 위치 내를 모두 죽음의 구역으로 색칠
        int sx = (x1 > x2) ? x2 : x1;
        int sy = (y1 > y2) ? y2 : y1;
        int ex = (x1 > x2) ? x1 : x2;
        int ey = (y1 > y2) ? y1 : y2;
        for(int x = sx; x < ex + 1; x++) {
            for(int y = sy; y < ey + 1; y++) {
                graph[x][y] = 1;
            }
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;

        // 입력받은 위치 내를 모두 위험한 구역으로 색칠
        int sx = (x1 > x2) ? x2 : x1;
        int sy = (y1 > y2) ? y2 : y1;
        int ex = (x1 > x2) ? x1 : x2;
        int ey = (y1 > y2) ? y1 : y2;
        for(int x = sx; x < ex + 1; x++) {
            for(int y = sy; y < ey + 1; y++) {
                graph[x][y] = -1;
            }
        }
    }

    cout << solve(0, 0) << endl;

    return 0;
}

int solve(int x, int y) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

    pq.push(make_pair(0, make_pair(x, y)));
    visited[x][y] = true;
    dist[x][y] = 0;
    while(!pq.empty()) {
        pair<int, pair<int, int> > now = pq.top();
        pq.pop();

        // cout << now.second.first << " " << now.second.second << endl;

        // 이미 갱신되었으면 패스
        if (now.first > dist[now.second.first][now.second.second]) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nx = now.second.first + dx[i];
            int ny = now.second.second + dy[i];

            // 범위 밖으로 나갈 경우, 진행 X
            if(nx < 0 || nx > 500 || ny < 0 || ny > 500) {
                continue;
            }

            // 방문한 적 있는 경우 패스
            if (visited[nx][ny]) {
                continue;
            }

            switch (graph[nx][ny]) {
                case -1:
                    break;
                case 1:
                    if(now.first + 1 < dist[nx][ny]) {
                        visited[nx][ny] = true;
                        dist[nx][ny] = now.first + 1;
                        pq.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
                    }
                    break;
                case 0:
                    if(now.first < dist[nx][ny]) {
                        visited[nx][ny] = true;
                        dist[nx][ny] = now.first;
                        pq.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
                    }
                    break;
            }
        }
    }

    return (dist[500][500] != MAX) ? dist[500][500] : -1;
}