#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int T, N, M, p, q;
int parent[10001];
bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    if(a.first == b.first) {
        if(a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}
vector<pair<int, pair<int, int> > > graph;
int find_parent(int parent[], int x);
void union_parent(int parent[], int a, int b);
bool mst();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N >> M >> p >> q;
        for(int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.push_back(make_pair(w, make_pair(u, v)));
        }

        string answer = (mst()) ? "YES" : "NO";
        cout << answer << endl;

        vector<pair<int, pair<int, int> > > temp;
        graph.swap(temp);
    }

    return 0;
}

int find_parent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = find_parent(parent, parent[x]);
    }

    return x;
}

void union_parent(int parent[], int a, int b) {
    int pa = find_parent(parent, a);
    int pb = find_parent(parent, b);

    if(pa < pb) {
        parent[pb] = pa;
    } else {
        parent[pa] = pb;
    }
}

bool mst() {
    bool result = false;

    // 부모 배열 초기화
    for(int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }

    sort(graph.begin(), graph.end(), compare);
    for(auto now: graph) {
        int x = now.second.first;
        int y = now.second.second;
        int cost = now.first;

        int px = find_parent(parent, x);
        int py = find_parent(parent, y);

        if(px != py) {            
            union_parent(parent, x, y);

            if((x == p && y == q) || (x == q && y == p)) {
                result = true;
            }
        }
    }

    return result;
}