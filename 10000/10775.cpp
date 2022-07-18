#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int g, p;
vector<int> node;
int parent[100001];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
int solve();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> g >> p;
    // parent 배열 초기화
    for(int i = 1; i < g + 1; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < p; i++) {
        int input;
        cin >> input;
        node.push_back(input);
    }

    cout << solve() << endl;

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

int solve() {
    int result = 0;

    for(auto now : node) {
        int nowP = findParent(parent, now);

        if(nowP == 0) {
            return result;
        }
        else {
            unionParent(parent, nowP, nowP - 1);
            result++;
        }
    }

    return result;
}