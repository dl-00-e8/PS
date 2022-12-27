#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int indigree[101];
int dp[101];
vector<pair<int, int>> graph[101];
void topologySort(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(indigree, 0, sizeof(indigree));
    memset(dp, 0, sizeof(dp));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        
        graph[x].push_back({y, k});
        indigree[y]++;
    }

    topologySort(n);

    return 0;
}

void topologySort(int start) {
    queue<int> q;

    q.push(start);
    dp[start] = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int node = graph[now][i].first;
            int cost = graph[now][i].second;

            indigree[node]--;
            dp[node] += dp[now] * cost;

            if(indigree[node] == 0) {
                q.push(node);
            }
        }
    }

    // Output
    for(int i = 1; i < n + 1; i++) {
        if(graph[i].size() == 0) {
            cout << i << " " <<  dp[i] << endl;
        }
    }
}