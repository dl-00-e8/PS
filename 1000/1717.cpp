#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int parent[1000001];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int num, a, b;
        cin >> num >> a >> b;
        if(num == 0) {
            unionParent(parent, a, b);
        }
        else if(num == 1) {
            if(findParent(parent, a) == findParent(parent, b)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }

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