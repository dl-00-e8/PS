#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M, t;
int parent[10001];
struct compare {
    bool operator()(pair<int, pair<int, int> >  a, pair<int, pair<int, int> >  b) {
        if(a.first == b.first) {
            return a.second.first > b.second.first;
        }

        return a.first > b.first;
    }
};
vector<pair<int, int> > graph[10001];
int find_parent(int x);
void union_parent(int a, int b);
int prim(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, 0, sizeof(parent));

    cin >> N >> M >> t;
    
    for(int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        graph[B].push_back(make_pair(A, C));
    }

    cout << prim(1) << endl;
    
    return 0;
}

int find_parent(int x) {
    if(parent[x] != x) {
        return parent[x] = find_parent(parent[x]);
    }

    return x;
}

void union_parent(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);

    if(pa < pb) {
        parent[pb] = pa;
    } else {
        parent[pa] = pb;
    }
}

int prim(int start) {
    int cnt = 0;
    int answer = 0;
    priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > > , compare> pq;
    for(auto data: graph[start]) {
        pq.push(make_pair(data.second, make_pair(start, data.first)));
    }

    while(!pq.empty()) {
        pair<int, pair<int, int> > now = pq.top();
        pq.pop();

        if(find_parent(now.second.first) == find_parent(now.second.second)) {
            continue;
        }
        union_parent(now.second.first, now.second.second);
        answer += now.first + (t * cnt);
        cnt++;

        for(auto data: graph[now.second.second]) {
            pq.push(make_pair(data.second, make_pair(now.second.second, data.first)));
        }
    }

    return answer;
}