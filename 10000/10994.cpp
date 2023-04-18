#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int graph[400][400];
void solve(int sx, int sy, int now);
void output();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    solve(1, 1, n);

    output();

    return 0;
}

void solve(int sx, int sy, int now) {
    int mx = sx + 4 * (now - 1);
    int my = sy + 4 * (now - 1);

    for(int i = sx; i < mx + 1; i++) {
        graph[i][sy] = 1;
        graph[i][my] = 1;
    }
    for(int i = sy; i < my + 1; i++) {
        graph[sx][i] = 1;
        graph[mx][i] = 1;
    }
    
    if(now == 1) {
        return ;
    }

    solve(sx + 2, sy + 2, now - 1);
}

void output() {
    int range = 1 + 4 * (n - 1);

    for(int i = 1; i < range +  1; i++) {
        for(int j = 1; j < range + 1; j++) {
            if(graph[i][j] == 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
