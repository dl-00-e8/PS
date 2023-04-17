#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int graph[7][7];
int dy[] = {-1, 0, 1};
int solve(int x, int y, int last);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
        }
    }

    int answer = INF;
    for(int i = 1; i < m + 1; i++) {
        answer = min(answer, solve(1, i, -1));
    }
    
    cout << answer << endl;

    return 0;
}

int solve(int x, int y, int last) {
    if(x == n + 1) {
        return 0;
    }

    int temp = INF;
    for(int i = 0; i < 3; i++) {
        if(last == i) {
            continue;
        }

        int ny = y + dy[i];

        if(ny < 1 || ny > m) {
            continue;
        }

        temp = min(temp, solve(x + 1, ny, i) + graph[x][y]);
    }

    return temp;
}