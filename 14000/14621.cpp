#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int parent[1001];
bool col[1001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }
    for(int i = 1; i < n + 1; i++) {
        char input;
        cin >> input;

        if(input == 'M') {
            col[i] = true;
        }
        else {
            col[i] = false;
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        pq.push({d, {u ,v}});
    }

    solve();

    return 0;
}

int findParent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = findParent(parent, parent[x]);
    }

    return parent[x];
}

void unionParent(int parent[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);

    if(pa < pb) {
        parent[pa] = pb;
    }
    else {
        parent[pb] = pa;
    }
}

void solve() {
    int cnt = 0;
    int result = 0;

    while(!pq.empty()) {
        int dist = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        
        pq.pop();

        if(findParent(parent, a) != findParent(parent, b) && col[a] != col[b]) {
            unionParent(parent, a, b);
            result += dist;
            cnt++;
        }
    }

    if(cnt == n - 1) {
        cout << result << endl;
    }
    else {
        cout << -1 << endl;
    }

}