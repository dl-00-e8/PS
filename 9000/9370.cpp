#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 200000000

int T, n, m, t, s, g, h;
vector<pair<int, int>> graph[2001];
int dist[2001];
//bool visited[2001];
vector<int> dest;
void dijkstra(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), INF);
        memset(graph, 0, sizeof(graph));
        //memset(visited, 0, sizeof(visited));
        vector<int>().swap(dest);

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for(int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            if((a == g && b == h) || (a == h && b == g)) {
                d = d * 2 - 1;
            }
            else {
                d = d * 2;
            }

            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }

        for(int i = 0; i < t; i++) {
            int x;
            cin >> x;
            dest.push_back(x);
        }

        dijkstra(s);
    }

    return 0;
}

void dijkstra(int start) {
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(cost > dist[now]) {
            continue;
        }

        for(int i = 0; i < graph[now].size(); i++) {
            if(cost + graph[now][i].second < dist[graph[now][i].first]) {
                /*
                cout << now << " " << graph[now][i].first << endl;
                cout << visited[now] << " " << visited[graph[now][i].first] << endl;
                */

                /*     
                // 최단 경로 시 해당 경로 지나는지 여부 갱신
                if(!visited[graph[now][i].first]) {
                    if(visited[now]) {
                        visited[graph[now][i].first] = true;
                    }

                    if((now == g && graph[now][i].first == h) || (now == h && graph[now][i].first == g)) {
                        visited[graph[now][i].first] = true;
                    }
                }
                else {
                    if(!visited[now]) {
                        visited[graph[now][i].first] = false;
                    }
                }
                */

                dist[graph[now][i].first] = cost + graph[now][i].second;
                pq.push({cost + graph[now][i].second, graph[now][i].first});
            }
        }
    }

    /*
    for(int i = 1 ; i < n + 1; i++) {
        cout << visited[i] << " ";
    }
    cout << endl;
    
    for(int i = 1 ; i < n + 1; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    */    

    for(int i = 0; i < dest.size(); i++) {
        if(dist[dest[i]] % 2 != 0) {
            result.push_back(dest[i]);
        }
    }

    sort(result.begin(), result.end(), less<int>());

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}