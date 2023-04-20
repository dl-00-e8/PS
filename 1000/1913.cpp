#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, input;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int graph[1000][1000];
void solve(int input);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n;
    cin >> input;

    solve(input);

    return 0;
}

void solve(int input) {
    int x, y, ax, ay, num, cnt, dir;

    dir = 0;
    num = 2;
    cnt = 1;
    x = (n / 2) + 1;
    y = (n / 2) + 1;
    graph[x][y] = 1;
    while(num < n * n + 1) {
        if(dir == 0) {
            for(int t = 0; t < cnt; t++) {
                x += dx[dir];
                y += dy[dir];
                graph[x][y] = num++;
            }
        }
        else if(dir == 1) {
            for(int t = 0; t < cnt; t++) {
                x += dx[dir];
                y += dy[dir];
                graph[x][y] = num++;
            }
            cnt++;
        }
        else if(dir == 2) {
            for(int t = 0; t < cnt; t++) {
                x += dx[dir];
                y += dy[dir];
                graph[x][y] = num++;
            }
        }
        else {
            for(int t = 0; t < cnt; t++) {
                x += dx[dir];
                y += dy[dir];
                graph[x][y] = num++;
            }
            cnt++;
        }

        dir = (dir + 1) % 4;
    }
    

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            cout << graph[i][j] << " ";
            if(graph[i][j] == input) {
                ax = i;
                ay = j;
            }
        }
        cout << endl;
    }
    cout << ax << " " << ay << endl;
}