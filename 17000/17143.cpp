#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int R, C, m;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int graph[101][101]; // 움직이기 전
int after[101][101]; // 움직인 후
pair<int, int> shark[10001]; // 상어 위치 정보
int speed[10001]; // 속력
int dir[10001]; // 방향
int vol[10001]; // 크기
bool death[10001]; // 포획 여부
void move(int idx);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(shark, 0, sizeof(shark));
    memset(speed, 0, sizeof(speed));
    memset(dir, 0, sizeof(dir));
    memset(vol, 0, sizeof(vol));
    memset(death, 0, sizeof(death));

    cin >> R >> C >> m;
    for(int i = 1; i < m + 1; i++) {
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;

        shark[i].first = r;
        shark[i].second = c;
        speed[i] = s;
        dir[i] = d;
        vol[i] = z;
        graph[r][c] = i;
    }

    solve();

    return 0;
}

void move(int idx) {
    int x = shark[idx].first;
    int y = shark[idx].second;
    int d = dir[idx];
    int s = speed[idx];


    // 속력만큼 움직여
    if(d == 1 || d == 2) {
        int r = (R - 1) * 2;
        if(s >= r) {
            s = s % r;
        }

        for(int i = 0; i < s; i++) {
            if(x == 1) {
                d = 2;
            }
            else if(x == R) {
                d = 1;
            }
            x = x + dx[d];
            y = y + dy[d];
        }
        
    }
    else {
        int r = (C - 1) * 2;
        if(s >= r) {
            s = s % r;
        }

        for(int i = 0; i < s; i++) {
            if(y == 1) {
                d = 3;
            }
            else if(y == C) {
                d = 4;
            }
            x = x + dx[d];
            y = y + dy[d];
        }
    }


    dir[idx] = d;
    shark[idx].first = x;
    shark[idx].second = y;

    if(after[x][y] != 0) {
        int t = after[x][y];

        if(vol[t] < vol[idx]) {
            after[x][y] = idx;
            death[t] = true;
        }
        else {
            death[idx] = true;
        }
    }
    else {
        after[x][y] = idx;
    }
}

void solve() {
    int answer = 0; // 상어 크기의 합

    for(int y = 1; y < C + 1; y++) { // 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
        int x = 1;

        // 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.
        while(graph[x][y] == 0 && x < R + 1) { // 상어 찾기
            x++;
        }
        if(x < R + 1) { // 상어 찾은 경우
            int now = graph[x][y]; 
            answer += vol[now]; // 상어 size 더하기
            graph[x][y] = 0; // 잡혔으므로 빈 칸 처리
            death[now] = true; // 포획 처리
        }

        // 3. 상어가 이동한다.
        memset(after, 0, sizeof(after));

        for(int i = 1; i < m + 1; i++) {
            if(death[i]) { // 상어가 이미 포획된 경우
                continue;
            }

            move(i);
        }

        // 복사
        for(int i = 1; i < R + 1; i++) {
            for(int j = 1; j < C + 1; j++) {
                graph[i][j] = after[i][j];
            }
        }
    }

    cout << answer << endl;
}