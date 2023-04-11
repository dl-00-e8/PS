#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
pair<int, int> node[123457]; // second.first = wolf, second.second = sheep
vector<int> graph[123457];
ll dfs(int x);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(node, 0, sizeof(node));

    cin >> n;
    for(int i = 2; i < n + 1; i++) {
        char t;
        int a, p;

        cin >> t >> a >> p;

        if(t == 'S') {
            node[i].first = 0;
            node[i].second = a;
            graph[p].push_back(i);
        }
        else {
            node[i].first = a;
            node[i].second = 0;
            graph[p].push_back(i);
        }
    }

    solve();

    return 0;
}

ll dfs(int x) {
    ll result = 0;
    
    for(int i = 0; i< graph[x].size(); i++) {
        result += dfs(graph[x][i]);
    }

    result += node[x].second;
    result -= node[x].first;

    if(result < 0) {
        result = 0;
    }

    return result;
}

void solve() {
    ll answer = 0;

    answer = dfs(1);

    cout << answer << endl;
}