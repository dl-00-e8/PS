#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int link[1001];
int dist[1001];
vector<pair<int, int>> graph[1001];
void solve(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(link, 0, sizeof(link));
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    solve(1);

    return 0;
}

void solve(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()) {
        pair<int, int> now = pq.top();

        pq.pop();

        if(dist[now.second] < now.first) {
            continue;
        }

        for(int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].first;
            int cost = graph[now.second][i].second;

            if(dist[next] > dist[now.second] + cost) {
                link[next] = now.second;
                dist[next] = dist[now.second] + cost;
                pq.push({dist[next], next});
            }
        }
    }

    int cnt = 0;
    vector<pair<int, int>> result;
    for(int i = 1; i < n + 1; i++) {
        if(link[i] != 0) {
            cnt++;
            result.push_back({i, link[i]});
        }
    }

    cout << cnt << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }
}