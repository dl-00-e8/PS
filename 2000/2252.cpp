#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
vector<int> graph[32001];
int indigree[32001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(indigree, 0, sizeof(indigree));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indigree[b]++;
    }

    solve();

    return 0;
}

void solve() {
    queue<int> q;

    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        cout << now << " ";

        for(auto visit : graph[now]) {
            indigree[visit]--;

            if(indigree[visit] == 0) {
                q.push(visit);
            }
        }
    }
}