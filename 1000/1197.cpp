#include <bits/stdc++.h>

using namespace std;

#define enld "\n"
#define ll long long

int v, e;
int parent[10001];
struct node {
    int x, y, cost;
};
vector<node> graph;
bool compare(const node &a, const node &b);
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(parent, 0, sizeof(parent));

    cin >> v >> e;
    for(int i = 1; i < v + 1; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < e; i++) {
        node temp;
        cin >> temp.x >> temp.y >> temp.cost;
        graph.push_back(temp);
    }

    solve();

    return 0;
}

bool compare(const node &a, const node &b) {
    if(a.cost == b.cost) {
        if(a.x == b.x) {
            return a.y < b.y;
        }

        return a.x < b.x;
    }
    return a.cost < b.cost;
}

int findParent(int parent[], int x) {
    if(parent[x] == x) {
        return parent[x];
    }

    return parent[x] = findParent(parent, parent[x]);
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
    ll result = 0;

    sort(graph.begin(), graph.end(), compare);

    for(auto now : graph) {
        if(findParent(parent, now.x) != findParent(parent, now.y)) {
            unionParent(parent, now.x, now.y);
            result += now.cost;
        }
    }

    cout << result << endl;
}