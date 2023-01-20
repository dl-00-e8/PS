#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int dx[] = {1, 0, 0}; // 위쪽으로 이동 불가
int dy[] = {0, -1, 1}; // 위쪽으로 이동 불가
int graph[1001][1001];
bool visited[1001][1001];
int dfs(int x, int y);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(vistied, 0, sizeof(visited));z

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
        }
    }

    solve();

    return 0;
}

int dfs(int x, int y) {
    
}

void solve() {

}