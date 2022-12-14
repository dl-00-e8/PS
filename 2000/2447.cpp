#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define max 6570

int n;
int graph[max][max];
void solve(int sx, int sy, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n;

    solve(1, 1, n);

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(graph[i][j] == 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

void solve(int sx, int sy, int cnt) {
    if(cnt == 3) {
        for(int i = sx; i < sx + cnt; i++) {
            for(int j = sy; j < sy + cnt; j++) {
                if(i == sx + 1 && j == sy + 1) {
                    continue;
                }
                
                graph[i][j] = 1;
            }
        }
    }
    else {
        int divCnt = cnt / 3;

        solve(sx, sy, divCnt);
        solve(sx + divCnt, sy, divCnt);
        solve(sx + (2 * divCnt), sy, divCnt);
        solve(sx, sy + divCnt, divCnt);
        solve(sx + (2 * divCnt), sy + divCnt, divCnt);
        solve(sx, sy + (2 * divCnt), divCnt);
        solve(sx + divCnt, sy + (2 * divCnt), divCnt);
        solve(sx + (2 * divCnt), sy + (2 * divCnt), divCnt);
    }
}