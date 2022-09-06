#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int t, n, d, c;
vector<pair<int, int>> graph[10001];
int dist[10001];
void dijkstra(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(graph, 0, sizeof(graph));
        fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), INF);

        cin >> n >> d >> c;
        for(int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            
            graph[b].push_back({a, s});
        }

        dijkstra(c);

        int cnt = 0;
        int total = 0;
        for(int i = 1; i < n + 1; i++) {
            if(dist[i] != INF) {
                cnt++;
                total = max(total, dist[i]);
            }
        }
        cout << cnt << " " << total << endl;
    }

    return 0;
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(dist[now] < cost) {
            continue;
        }

        for(int i = 0; i < graph[now].size(); i++) {
            if(graph[now][i].second + cost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = graph[now][i].second + cost;

                pq.push({dist[graph[now][i].first], graph[now][i].first});
            }
        }
    }
    
    
}