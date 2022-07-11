#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

bool result;
int n, m, before;
vector<int> data;
int parent[201];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            int input;
            cin >> input;

            if(input == 1) {
                unionParent(parent, i, j);
            }
        }
    }

    result = true;
    for(int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if(i == 0) {
            before = input;
        }
        else {
            if(findParent(parent, before) != findParent(parent, input)) {
                result = false;
                break;
            }
            else {
                before = input;
            }
        }
    }

    if(result) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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