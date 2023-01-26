#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
int parent[1001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void kruskal();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            int input;
            cin >> input;
            pq.push({input, {i, j}});
        }
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
        parent[pa] = pb;
    }
    else {
        parent[pb] = pa;
    }
}

void kruskal() {
    ll result = 0;
    
    // Parent 배열 초기화
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    // Krusakl
    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(findParent(parent, x) != findParent(parent, y)) {
            unionParent(parent, x, y);
            result += cost;
        }
    }

    cout << result << endl;
}