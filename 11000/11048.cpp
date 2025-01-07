#include <bits/stdc++.h>

using namespace std;

#define endl "\n" 

int N, M;
int miro[1001][1001];
int visited[1001][1001];
void dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(miro, 0, sizeof(miro));
    memset(visited, 0, sizeof(visited));

    cin >> N >> M;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            cin >> miro[i][j];
        }
    }

    dp();

    return 0;
}

void dp() {
    int dx[] = {-1, 0, -1};
    int dy[] = {0, -1, -1};
    queue<pair<int, int> > q;

    q.push(make_pair(N, M));
    visited[N][M] = miro[N][M];
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i < 3; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > M) {
                continue;
            }

            if(visited[now.first][now.second] + miro[nx][ny] > visited[nx][ny]) {
                visited[nx][ny] = visited[now.first][now.second] + miro[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << visited[1][1] << endl;
}