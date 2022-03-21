#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, result;
int length(char c);
int parent[51];
vector<pair<int, pair<int, int>>> graph;
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    result = 0;
    for(int i = 1; i < n + 1; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < n; j++) {
            if(i == j + 1) {
                if(input[j] != '0') {
                    result += length(input[j]);
                }
            }
            else {
                if(input[j] != '0') {
                    result += length(input[j]);
                    graph.push_back({length(input[j]), {i , j + 1}});
                }
            }
        }
    }

    solve();

    return 0;
}

int length(char c) {
    if(c == '0') {
        return 0;
    }
    else if(c - 'a' >= 0) {
        return c - 'a' + 1;
    }
    else if(c - 'a' < 0) {
        return c - 'A' + 27;
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
        parent[pb] = pa;
    }
    else {
        parent[pa] = pb;
    }
}

void solve() {
    // 부모노드 초기화
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    sort(graph.begin(), graph.end(), less<pair<int, pair<int, int>>>());

    for(auto now : graph) {
        int cost = now.first;
        int a = now.second.first;
        int b = now.second.second;

        if(findParent(parent, a) != findParent(parent, b)) {
            unionParent(parent, a, b);
            result -= cost;
        }
    }

    for(int i = 1; i < n + 1; i++) {
        if(findParent(parent, i) != parent[1]) {
            cout << -1 << endl;
            return ;
        }
    }

    cout << result << endl;
}