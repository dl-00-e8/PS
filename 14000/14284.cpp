#include <bits/stdc++.h> 

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m, s, t;
int dist[5001];
vector<pair<int, int>> graph[5001];
void dijkstra(int start, int dest);

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
    cin >> s >> t;

    dijkstra(s, t);

    return 0;
}

void dijkstra(int start, int dest) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(cost > dist[now]) {
            continue;
        }

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int ncost = graph[now][i].second;

            if(cost + ncost < dist[next]) {
                dist[next] = cost + ncost;
                pq.push({dist[next], next});
            }
        }
    }

    answer = dist[dest];

    cout << answer << endl;
}