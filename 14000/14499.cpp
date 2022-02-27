#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int n, m, x, y, k;
int graph[21][21];
vector<int> dice(7, 0);
vector<int> order;
vector<int> diceMove(int dir);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    for(int i = 0; i < k; i++) {
        int input;
        cin >> input;
        order.push_back(input);
    }

    solve();

    return 0;
}

vector<int> diceMove(int dir) {
    vector<int> move(7, 0);

    if(dir == 1) {
        move[1] = dice[4];
        move[2] = dice[2];
        move[3] = dice[1];
        move[4] = dice[6];
        move[5] = dice[5];
        move[6] = dice[3];
    }
    else if(dir == 2){
        move[1] = dice[3];
        move[2] = dice[2];
        move[3] = dice[6];
        move[4] = dice[1];
        move[5] = dice[5];
        move[6] = dice[4];
    }
    else if(dir == 3) {
        move[1] = dice[5];
        move[2] = dice[1];
        move[3] = dice[3];
        move[4] = dice[4];
        move[5] = dice[6];
        move[6] = dice[2];
    }
    else {
        move[1] = dice[2];
        move[2] = dice[6];
        move[3] = dice[3];
        move[4] = dice[4];
        move[5] = dice[1];
        move[6] = dice[5];
    }

    return move;
}

void solve() {
    int nx, ny;
    int dx[] = {0, 0, 0, -1, 1};
    int dy[] = {0, 1, -1, 0, 0};

    for(int i = 0; i < k; i++) {
        nx = x + dx[order[i]];
        ny = y + dy[order[i]];

        // 지도 밖 예외처리
        if(0 > nx || nx >= n || 0 > ny || ny >= m) {
            continue;
        }

        // 주사위 이동 및 설정
        dice = diceMove(order[i]);

        if(graph[nx][ny] == 0) {
            graph[nx][ny] = dice[6];
        }
        else {
            dice[6] = graph[nx][ny];
            graph[nx][ny] = 0;
        }
                
        // 주사위의 윗 면에 쓰여 있는 수 출력
        cout << dice[1] << endl;

        // 이동한 위치를 현 위치로 저장
        x = nx;
        y = ny;
    }
}
