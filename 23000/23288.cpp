#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M, K, dir, answer;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dice[6] = {1, 6, 3, 4, 5, 2}; // 순서대로, 윗면/아랫면/동/서/남/북
pair<int, int> now = make_pair(1, 1);
int graph[21][21];
bool visited[21][21];
void change_dir(int rotate); // true면 시계방향, false면 반시계방향
int bfs(int x, int y);
void roll(int dir);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    cin >> N >> M >> K;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            cin >> graph[i][j];
        }
    }

    answer = 0;
    dir = 0; // 처음 바라보는 방향은 동쪽
    while(K--) {
        int nx = now.first + dx[dir];
        int ny = now.second + dy[dir];

        // 이동방향을 반대로 뒤집어야 하는 경우
        if(nx < 1 || nx > N || ny < 1 || ny > M) {
            change_dir(2);
            nx = now.first + dx[dir];
            ny = now.second + dy[dir];
        }
        roll(dir);
        // cout << nx << " " << ny << " " << dir << endl;
        

        int cnt = bfs(nx, ny);
        answer += (cnt * graph[nx][ny]);
        
        // cout << dice[1] << " " << graph[nx][ny] << endl;
        if(dice[1] > graph[nx][ny]) {
            change_dir(0);
        } else if(dice[1] < graph[nx][ny]) {
            change_dir(1);
        }

        now.first = nx;
        now.second = ny;
    }

    cout << answer << endl;

    return 0;
}

void change_dir(int rotate) { // true면 시계방향, false면 반시계방향
    if(rotate == 0) {
        dir++;

        if(dir == 4) {
            dir = 0;
        }
    } else if(rotate == 1) {
        dir--;

        if(dir == -1) {
            dir = 3;
        }
    } else {
        if(dir == 0) {
            dir = 2;
        } else if(dir == 1) {
            dir = 3;
        } else if(dir == 2) {
            dir = 0;
        } else {
            dir = 1;
        }
    }
}

void roll(int dir) { // 순서대로, 윗면/아랫면/동/서/남/북
    int temp;
    if(dir == 0) { // 동쪽 0 2 1 3
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    } else if(dir == 2) { // 서쪽 0 3 1 2
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    } else if(dir == 1) { // 남쪽 0 4 1 5
        temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    } else if(dir == 3) { // 북쪽 0 5 1 4
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
}

int bfs(int x, int y) {
    int result = 0;
    queue<pair<int, int> > q;

    memset(visited, 0, sizeof(visited));

    q.push(make_pair(x, y));
    visited[x][y] = true;
    result++;
    while(!q.empty()) {
        pair<int, int> loc = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = loc.first + dx[d];
            int ny = loc.second + dy[d];

            if(nx < 1 || nx > N || ny < 1 || ny > M) {
                continue;
            }

            if(graph[nx][ny] == graph[x][y] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                result++;
            }
        }
    }

    return result;
}