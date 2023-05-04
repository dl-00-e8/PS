#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int parent[1001];
vector<pair<int, pair<int, int>>> graph;
bool compare1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b);
bool compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b);
void unionParent(int parent[], int a, int b);
int findParent(int parent[], int x);
int kruskal_min(int start);
int kruskal_max(int start);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, 0, sizeof(parent));

    cin >> n >> m;
    
    for(int i = 0; i < m + 1; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }

    solve();

    return 0;
}

bool compare1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.first == b.first) {
        if(a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }

        return a.second.first < b.second.first;
    }

    return a.first > b.first;
}
bool compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.first == b.first) {
        if(a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }

        return a.second.first < b.second.first;
    }

    return a.first < b.first;
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

int findParent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = findParent(parent, parent[x]);
    }

    return x;
}

int kruskal_min(int start) {
    int result = 0;

    sort(graph.begin(), graph.end(), compare1);
    
    for(auto now : graph) {
        // cout << now.first << " " << now.second.first << " " << now.second.second << endl;
        if(findParent(parent, now.second.first) != findParent(parent, now.second.second)) {
            unionParent(parent, now.second.first, now.second.second);

            if(now.first == 0) {
                result++;
            }
        }
    }

    return pow(result, 2);
}

int kruskal_max(int start) {
    int result = 0;

    sort(graph.begin(), graph.end(), compare2);
    
    for(auto now : graph) {
        // cout << now.first << " " << now.second.first << " " << now.second.second << endl;
        if(findParent(parent, now.second.first) != findParent(parent, now.second.second)) {
            unionParent(parent, now.second.first, now.second.second);

            if(now.first == 0) {
                result++;
            }
        }
    }

    return pow(result, 2);
}

void solve() {
    int min, max;

    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }
    min = kruskal_min(0);
    
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }
    max = kruskal_max(0);

    cout << max - min << endl;
}