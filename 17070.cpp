#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int graph[17][17];
int dp[17][17][3]; // 가로 = 0, 세로 = 1, 대각선 = 2
void move(int x, int y, int dir); // 각 위치 및 방향별 움직이는 함수
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    if(graph[n - 1][n - 1] == 1 || graph[0][0] == 1 || graph[0][1] == 1) {
        cout << 0 << endl;
    }
    else {
        memset(dp, 0, sizeof(dp)); // dp 배열 초기화
        dp[0][1][0] = 1;
        solve();
    }
    
    return 0;
}

void move(int x, int y, int dir) {
    if(dir == 0) {
        // 파이프 방향이 가로인 경우
        if(0 <= x && x < n && 0 <= y + 1 && y + 1 < n) {
            if(graph[x][y + 1] != 1) {
                dp[x][y + 1][0] += dp[x][y][dir];
            }
        }

        if(0 <= x + 1 && x + 1 < n && 0 <= y + 1 && y + 1 < n) {
            if(graph[x +1][y + 1] != 1 && graph[x + 1][y] != 1 && graph[x][y + 1] != 1) {
                dp[x + 1][y + 1][2] += dp[x][y][dir];
            }
        }
    
    }
    else if(dir == 1) {
        // 파이프 방향이 세로인 경우
        if(0 <= x + 1 && x + 1 < n && 0 <= y && y < n) {
            dp[x + 1][y][1] += dp[x][y][dir];
        }

        if(0 <= x + 1 && x + 1 < n && 0 <= y + 1 && y + 1 < n) {
            if(graph[x +1][y + 1] != 1 && graph[x + 1][y] != 1 && graph[x][y + 1] != 1) {
                dp[x + 1][y + 1][2] += dp[x][y][dir];
            }
        }
    }
    else if(dir == 2) {
        // 파이프 방향이 대각선인 경우
        if(0 <= x && x < n && 0 <= y + 1 && y < n) {
            if(graph[x][y + 1] != 1) {
                dp[x][y + 1][0] += dp[x][y][dir];
            }
        }

        if(0 <= x + 1 && x + 1 < n && 0 <= y + 1 && y < n) {
            if(graph[x +1][y + 1] != 1 && graph[x + 1][y] != 1 && graph[x][y + 1] != 1) {
                dp[x + 1][y + 1][2] += dp[x][y][dir];
            }
        }

        if(0 <= x + 1 && x + 1 < n && 0 <= y && y < n) {
            if(graph[x +1][y] != 1) {
                dp[x + 1][y][1] += dp[x][y][dir];
            }
        }
    }

}

void solve() {
    int result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            
            for(int k = 0; k < 3; k++) {
                if(graph[i][j] != 1) {
                    move(i, j, k);
                }
            }
        }
    }

    result = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];

    cout << result << endl;
}