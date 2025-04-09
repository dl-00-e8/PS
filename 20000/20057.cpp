#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, dir, answer, mv_cnt, length, visited, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
pair<int, int> now;
int graph[500][500];
void change_dir();
int calc(int x, int y, int dir);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> N;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < N + 1; j++) {
            cin >> graph[i][j];
        }
    }
    now.first = (N / 2) + 1;
    now.second = now.first;

    cnt = 0;
    answer = 0;
    mv_cnt = 0;
    length = 1;
    visited = 0;
    while(visited < N * N) {
        // 방향 이동 및 방문 카운트 증가
        now.first = now.first + dx[dir];
        now.second = now.second + dy[dir];

        // 모래 흩날리기
        // cout << now.first << " " << now.second << " " << graph[now.first][now.second] << endl;
        int t = calc(now.first, now.second, dir);
        answer += t;
        

        // 회전 계산
        mv_cnt++;
        visited++;
        if (mv_cnt == length) {
            mv_cnt = 0;
            change_dir();
            cnt++;

            if (cnt == 2) {
                cnt = 0;
                length++;
            }
        }   
    }

    cout << answer << endl;

    return 0;
}

void change_dir() {
    dir++;

    if(dir == 4) {
        dir = 0;
    }
}

int calc(int x, int y, int dir) {
    // 방향 순서: 0=←, 1=↓, 2=→, 3=↑
    int sandX[4][10] = {
        {-1, 1, -2, 2, 0, -1, 1, -1, 1, 0},  // ←
        {-1, -1, 0, 0, 2, 0, 0, 1, 1, 1},    // ↓
        {1, -1, 2, -2, 0, 1, -1, 1, -1, 0},  // →
        {1, 1, 0, 0, -2, 0, 0, -1, -1, -1}   // ↑
    };
    
    int sandY[4][10] = {
        {1, 1, 0, 0, -2, 0, 0, -1, -1, -1},   // ←
        {-1, 1, -2, 2, 0, -1, 1, -1, 1, 0},  // ↓
        {-1, -1, 0, 0, 2, 0, 0, 1, 1, 1},   // →
        {1, -1, 2, -2, 0, 1, -1, 1, -1, 0}   // ↑
    };

    int ratio[9] = {1, 1, 2, 2, 5, 7, 7, 10, 10}; // -1은 알파 위치 표시용
    
    int sand = graph[x][y];
    int spread = 0; // 흩날린 모래 총합
    int result = 0; // 나간 모래 총합
    
    for(int i = 0; i < 9; i++) {
        int nx = x + sandX[dir][i];
        int ny = y + sandY[dir][i];
        
        // 알파 위치 계산
        int amount = (sand * ratio[i]) / 100;
        spread += amount;
        
        if(nx < 1 || nx > N || ny < 1 || ny > N) {
            result += amount;
        } else {
            graph[nx][ny] += amount;
        }

        // cout << nx << " " << ny << " " << amount << " " << result << endl;
    }

    // 알파 위치 계산 (9번 인덱스)
    int nx = x + sandX[dir][9];
    int ny = y + sandY[dir][9];
    int alpha = sand - spread;
    // cout << nx << " " << ny << " " << alpha << " " << result << endl;

    if(nx < 1 || nx > N || ny < 1 || ny > N) {
        result += alpha;
    } else {
        graph[nx][ny] += alpha;
    }
    
    graph[x][y] = 0;
    return result;
}