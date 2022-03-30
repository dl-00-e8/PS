#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int indigree[32001];
vector<int> seq[32001];
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
        indigree[b]++;
        seq[a].push_back(b);
    }

    solve();

    return 0;
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();

        cout << now << " ";

        for(auto idx : seq[now]) {
            indigree[idx]--;

            if(indigree[idx] == 0) {
                pq.push(idx);
            }
        }
    }
}