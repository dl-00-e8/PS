#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int N;
vector<int> tree[100001];
int dp[100001];
int dfs(int now, int parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1,0);

    for(int i = 1; i < N + 1; i++) {
        if(dp[i] >= 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}

int dfs(int now, int parent) {
    int minNum = INF;
    
    for(auto value: tree[now]) {
        if(value == parent) {
            continue;
        }

        minNum = min(dfs(value, now), minNum);
    }

    if(minNum == INF) {
        dp[now] = now;
    } else {
        dp[now] = now - minNum;
    }

    return dp[now];
}