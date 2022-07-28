#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, r, d, X, Y;
double result = 0;
vector<pair<int, int>> tower;
vector<int> reach; // 도달 가능한 타워들의 idx value
vector<int> notReach; // 도달하지 못하는 타워들의 idx value
int visited[51];
double dist(int x1, int y1, int x2, int y2);
void bfs(int idx);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> d >> X >> Y;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tower.push_back({x, y});

        // 사정 거리 안에 있는지 여부
        if(dist(x, y, X, Y) <= r) {
            result += d;
            reach.push_back(i);
        }
        else {
            notReach.push_back(i);
        }
    }

    solve();

    return 0;
}

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y2 - y1), 2));
}

void bfs(int idx) {
    queue<int> q;

    q.push(idx);
    visited[idx] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            // 자기 자신이 dest가 되는 경우 제외
            if(now == i) {
                continue;
            }

            // 만약 해당 타워의 거리가 사정거리 이내이면서, 이미 방문하지 않은 경우라면
            if(dist(tower[now].first, tower[now].second, tower[i].first, tower[i].second) <= r && !visited[i]) {
                q.push(i);
                visited[i] = visited[now] + 1;
            }
        }
    }
}

void solve() {
    // 탑으로 가지 못하는 정점에 대한 BFS 수행
    for(int i = 0; i < notReach.size(); i++) {
        memset(visited, 0, sizeof(visited));
        
        bfs(notReach[i]);

        int minCnt = 987654321;
        for(int j = 0; j < reach.size(); j++) {
            if(visited[reach[j]] != 0) {
                minCnt = min(visited[reach[j]], minCnt);
            }
        }    

        result += (double)d / pow(2, minCnt);
    }

    cout << fixed;
    cout.precision(2);
    cout << result << endl;
}