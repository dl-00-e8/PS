#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dLine[200001];
int parent[200001];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dLine, 0, sizeof(dLine));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
        int deadline, input;
        cin >> deadline >> input;

        pq.push({input, deadline});
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
        parent[pb] = pa;
    }
    else {
        parent[pa] = pb;
    }
}

void solve() {
    int time = 0;
    int result = 0;

    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        if(time > n) {
            break;
        }

        // dLine ¼øÈ¸
        int idx = findParent(parent, now);
        if(idx > 0) {
            dLine[now] = cost;
            result += cost;
            
            unionParent(parent, idx, idx - 1);
        }
        else {
            continue;
        }
    }

    cout << result << endl;
}