#include <bits/stdc++.h>

using namespace std;

#define endl "\n" 
#define ll long long
#define INF 987654321

int n, e, v1, v2;
vector<pair<int, int>> graph[801];
ll dist[801];
void dijkstra(int start);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    solve();

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

        if(dist[now] < cost) {
            continue;
        }

        for(auto visit : graph[now]) {
            if(dist[visit.first] > cost + visit.second) {
                dist[visit.first] = cost + visit.second;
                pq.push({cost + visit.second, visit.first});
            }
        }
    }
}

void solve() {
    ll result = 0;
    ll firstResult = 0;
    ll secondResult = 0;

    // 1 다익스트라
    fill(dist, dist + sizeof(dist) / sizeof(ll), INF);
    dijkstra(1);
    firstResult += dist[v1];
    secondResult += dist[v2];

    // v1 다익스트라
    fill(dist, dist + sizeof(dist) / sizeof(ll), INF);
    dijkstra(v1);
    firstResult += dist[v2];
    secondResult += dist[n];

    // v2 다익스트라
    fill(dist, dist + sizeof(dist) / sizeof(ll), INF);
    dijkstra(v2);
    firstResult += dist[n];
    secondResult += dist[v1];

    result = min(firstResult, secondResult);
    if(result >= INF) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }
}