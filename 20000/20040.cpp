#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int parent[500001];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for(int i = 1; i < m + 1; i++) {
        int a, b;
        cin >> a >> b;
        if(findParent(parent, a) != findParent(parent, b)) {
            unionParent(parent, a, b);
        }
        else {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

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