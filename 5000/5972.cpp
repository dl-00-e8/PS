#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int dist[50001];
vector<pair<int ,int>> graph[50001];
void dijkstra(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(1);

    return 0;
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(cost > dist[now]) {
            continue;
        }

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int ncost = graph[now][i].second;

            if(dist[next] > dist[now] + ncost) {
                dist[next] = dist[now] + ncost;
                pq.push({dist[next], next});
            }
        }
    }

    cout << dist[n] << endl;
}