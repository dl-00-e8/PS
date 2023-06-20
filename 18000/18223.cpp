#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int v, e, p;
int dist[5001];
int parent[5001];
vector<pair<int, int> > graph[5001];
void dijkstra(int start);
void check();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, 0, sizeof(parent));
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), INF);

    cin >> v >> e >> p;
    for(int i = 0; i < e; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    dijkstra(1);

    check();

    return 0;
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(0, start));
    dist[start] = 0;
    parent[start] = -1;
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
                parent[next] = now;
                pq.push(make_pair(dist[next], next));
            }
            else if(dist[next] == dist[now] + ncost) {
                if(now == p) {
                    parent[next] = now;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }
    }
}

void check() {
    // for(int i = 1; i < v + 1; i++) {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;

    int now = v;
    while(parent[now] != -1) {
        now = parent[now];

        if(now == p) {
            cout << "SAVE HIM" << endl;
            return ;
        }
    }

    cout << "GOOD BYE" << endl;
}