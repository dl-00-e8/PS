#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 300000000

int tc, n, m, w;
int dist[501];
vector<pair<pair<int, int>, int>> graph;
void bellmanFord(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--) {
        fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), INF);

        cin >> n >> m >> w;
        for(int i = 0; i < m; i++) {
            int s, e, t;

            cin >> s >> e >> t;
            graph.push_back({{s, e}, t});
            graph.push_back({{e, s}, t});
        }
        for(int i = 0; i < w; i++) {
            int s, e, t;

            cin >> s >> e >> t;
            graph.push_back({{s, e}, -t});
        }

        bellmanFord(1);

        // graph √ ±‚»≠
        vector<pair<pair<int, int>, int>>().swap(graph);
    }

    return 0;
}

void bellmanFord(int start) {

    dist[start] = 0;

    for(int i = 1; i < n + 1; i++) {
        for(int j = 0; j < graph.size(); j++) {
            int now = graph[j].first.first;
            int next = graph[j].first.second;
            int cost = graph[j].second;

            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;

                if(i == n) {
                    cout << "YES" << endl;
                    return ;
                }
            }
        }
    }

    cout << "NO" << endl;
}