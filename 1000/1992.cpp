#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int graph[65][65];
void dq(int sx, int sy, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            char input;
            cin >> input;
            if(input - '0' == 1) {
                graph[i][j] = 1;
            }
            else if(input - '0' == 0) {
                graph[i][j] = 0;
            }
        }
    }

    dq(1, 1, n);

    return 0;
}

void dq(int sx, int sy, int cnt) {
    if(cnt == 1) {
        cout << graph[sx][sy];
        return ;
    }

    int num = graph[sx][sy];
    bool recursive = false;
    
    for(int i = sx; i < sx + cnt; i++) {
        for(int j = sy; j < sy + cnt; j++) {
            if(graph[i][j] != num) {
                recursive = true;
                break;
            }
        }
    }

    // cout << "sx : " << sx << " sy : " << sy << " cnt : " << cnt << " / " << recursive << endl;

    if(recursive) {
        int mx = sx + cnt / 2;
        int my = sy + cnt / 2;

        cout << '(';
        dq(sx, sy, cnt / 2);
        dq(sx, my, cnt / 2);
        dq(mx, sy, cnt / 2);
        dq(mx, my, cnt / 2); 
        cout << ')';
    }
    else { 
        cout << num;
    }
}