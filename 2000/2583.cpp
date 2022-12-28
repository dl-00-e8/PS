#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int m, n, k;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[101][101];
int areaSize[100001];
void color(int ldx, int ldy, int rux, int ruy);
void dfs(int x, int y, int idx);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(areaSize, 0, sizeof(areaSize));

    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        int ldx, ldy, rux, ruy;
        cin >> ldx >> ldy >> rux >> ruy;
        color(m - ldy, ldx, m - ruy, rux);
    }

    solve();

    return 0;
}

void color(int ldx, int ldy, int rux, int ruy) {
    for(int i = rux; i < ldx; i++) {
        for(int j = ldy; j < ruy; j++) {
            graph[i][j] = -1;
        }
    }
}

void dfs(int x, int y, int idx) {
    graph[x][y] = idx;
    areaSize[idx]++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || m <= nx || 0 > ny || n <= ny) {
            continue;
        }

        if(graph[nx][ny] == 0) {
            dfs(nx, ny, idx);
        }
    }
}

void solve() {
    int idx = 1;
 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == 0){
                dfs(i, j, idx);
                idx++;
            }
        }
    }

    sort(&areaSize[1], &areaSize[1] + idx - 1, less<int>());


    cout << idx - 1 << endl;
    for(int i = 1; i < idx; i++) {
        cout << areaSize[i] << " ";
    }
}