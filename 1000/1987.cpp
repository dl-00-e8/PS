#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int r, c;
bool already[27]; // 이미 방문한 집합
int graph[21][21];
int backTracking(int x, int y, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(already, 0, sizeof(already));

    cin >> r >> c;
    for(int i = 1; i < r + 1; i++) {
        for(int j = 1; j < c + 1; j++) {
            char input;
            cin >> input;
            graph[i][j] = input - 'A';
        }
    }

    cout << backTracking(1, 1, 1) << endl;

    return 0;
}

int backTracking(int x, int y, int cnt) {
    int maxCnt = cnt;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    already[graph[x][y]] = true;
 
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > r || ny < 1 || ny > c) {
            continue;
        }

        if(already[graph[nx][ny]] == false) {
            maxCnt = max(maxCnt, backTracking(nx, ny, cnt + 1));
        }
    }

    already[graph[x][y]] = false;

    return maxCnt;
}