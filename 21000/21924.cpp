#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, m;
ll total;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int parent[100001];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void kruskal();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, 0, sizeof(parent));

    cin >> n >> m;
    // 부모 배열 초기화
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    total = 0;
    for(int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        pq.push({c, {a, b}});
        total += c;
    }

    kruskal();

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

void kruskal() {
    vector<int> result;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(findParent(parent, x) != findParent(parent, y)) {
            unionParent(parent, x, y);
            result.push_back(cost);
        }
    }

    if(result.size() != n - 1) {
        cout << -1 << endl;
    }
    else {
        for(int i = 0; i < result.size(); i++) {
            total -= result[i];
        }

        cout << total << endl;
    }

    
}