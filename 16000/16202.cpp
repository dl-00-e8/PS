#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M, K;
int parent[1001];
vector<pair<int, pair<int, int> > > graph;
bool compare(pair<int, pair<int ,int> > a, pair<int, pair<int, int> > b) {
    if(a.first == b.first) {
        if(a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}
int find_parent(int parent[], int x);
void union_parent(int parent[], int a, int b);
int mst();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, 0, sizeof(parent));

    cin >> N >> M >> K;
    for(int i = 1; i < M + 1; i++) {
        int x, y;
        cin >> x >> y;
        graph.push_back(make_pair(i, make_pair(x, y)));
    }

    // 턴 별로 진행
    bool finish = false;
    while(K--) {
        // 0이 되어 탈출하여 턴이 남았다고 간주하고 0을 남은 턴동안 계속 출력
        if(finish) {
            cout << 0 << " ";
            continue;
        }

        int answer = mst();

        // 0이 나오면 출력하고 반복문 탈출
        if(answer == 0) {
            cout << answer << " ";
            finish = true;
            continue;
        } else {
            cout << answer << " ";
        }

        // 최소 비용 간선 제거
        graph.erase(graph.begin());
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

int mst() {
    int result = 0;

    // 부모 노드 초기화
    for(int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }

    // 간선 정렬
    sort(graph.begin(), graph.end(), compare);
    for(auto node: graph) {
        int x = node.second.first;
        int y = node.second.second;
        int cost = node.first;

        int px = find_parent(parent, x);
        int py = find_parent(parent, y);

        if(px != py) {
            union_parent(parent, x, y);
            result += cost;
        }
    }

    // MST를 구성하는지 확인
    int p1 = find_parent(parent, 1);
    for(int i = 2; i < N + 1; i++) {
        if(find_parent(parent, i) != p1) {
            return 0;
        }
    }

    return result;
}