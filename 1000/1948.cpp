#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, start, dest;
int indigree[10001];
int rindigree[10001];
int dist[10001];
int rdist[10001];
vector<pair<int, int>> graph[10001];
vector<pair<int, int>> rgraph[10001];
int topologySort1(int s, int e);
void topologySort2(int s, int e);
int findCount(int s, int e);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(indigree, 0, sizeof(indigree));
    memset(rindigree, 0, sizeof(rindigree));
    memset(dist, -1, sizeof(dist));
    memset(rdist, -1, sizeof(rdist));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        rgraph[b].push_back({a, c});
        indigree[b]++;
        rindigree[a]++;
    }
    cin >> start >> dest;

    solve();

    return 0;
}

int topologySort1(int s, int e) {
    queue<int> q;

    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int now = q.front();

        q.pop();

        for(int i  = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;

            dist[next] = max(dist[next], dist[now] + cost);

            indigree[next]--;

            if(indigree[next] == 0) {
                q.push(next);
            }
        }
    }

    return dist[e];
}

void topologySort2(int s, int e) {
    queue<int> q;

    q.push(s);
    rdist[s] = 0;
    while(!q.empty()) {
        int now = q.front();

        q.pop();

        for(int i = 0; i < rgraph[now].size(); i++) {
            int next = rgraph[now][i].first;
            int cost = rgraph[now][i].second;

            rdist[next] =  max(rdist[next], rdist[now] + cost);

            rindigree[next]--;
            if(rindigree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int findCount(int s, int e) {
    int answer = 0;
    queue<int> q;
    bool visited[10001];

    memset(visited, 0, sizeof(visited));
    
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int now = q.front();

        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;

            if(dist[next] + rdist[next] == dist[e] && dist[next] - dist[now] == cost) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                } 
                
                // cout << now << " " << next << endl;
                answer++;
                
            }
        }
    }

    return answer;
}

void solve() {
    cout << topologySort1(start, dest) << endl;
    topologySort2(dest, start);

    // for(int i = 1; i < n + 1; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    // for(int j = 1; j < n + 1; j++) {
    //     cout << rdist[j] << " ";
    // }
    // cout << endl;

    cout << findCount(start, dest) << endl;
}