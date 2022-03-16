#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
double result;
int parent[1001];
vector<pair<int, int>> graph;
double dist(int x1, int y1, int x2, int y2);
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
double solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // 부모 노드 초기화
    result = 0;
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph.push_back({x, y});
    }

    // 이미 연결된 통로 계산
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if(findParent(parent, a) != findParent(parent, b)) {
            unionParent(parent, a, b);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << solve() << endl;
    cout.unsetf(ios::fixed);

    return 0;
}

double dist(int x1, int y1, int x2, int y2) {
    double result = sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));

    return result;
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

double solve() {
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

    for(int i = 1; i < n + 1; i++) {
        for(int j = i + 1; j < n + 1; j++) {
            if(findParent(parent, i) != findParent(parent, j)) {
                double d = dist(graph[i - 1].first, graph[i - 1].second, graph[j - 1].first, graph[j - 1].second);
                pq.push({d, {i , j}});
            }
        }
    }

    while(!pq.empty()) {
        double cost = pq.top().first;
        long long x = pq.top().second.first;
        long long y = pq.top().second.second;

        pq.pop();

        if(findParent(parent, x) != findParent(parent ,y)) {
            result += cost;
            unionParent(parent, x, y);
        }
    }

    return result;
}