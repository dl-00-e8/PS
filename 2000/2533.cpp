#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<int> graph[1000001];
bool visited[1000001];
int dp[1000001][2];
void dfs(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, 0, sizeof(visited));
    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}

void dfs(int start) {
    visited[start] = true;
    dp[start][0] = 1;
    dp[start][1] = 0;

    for(int i = 0; i < graph[start].size(); i++) {
        int node = graph[start][i];
        
        if(!visited[node]) {
            dfs(node);

            dp[start][1] += dp[node][0];
            dp[start][0] += min(dp[node][0], dp[node][1]);
        }
    }   
}