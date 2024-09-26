#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
int graph[101][101];
bool visited[101][101]; // 외부 공기인지 확인 배열
queue<pair<int, int> > air; // 외부 공기 Queue
queue<pair<int, int> > cheese; // 치즈 Queue
queue<pair<int, int> > temp; // 다음 차례의 외부 공기 Queue
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> N >> M;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            cin >> graph[i][j];
            
            if(graph[i][j]) {
                cheese.push(make_pair(i, j));
            }
        }
    }

    solve();

    return 0;
}

void solve() {
    int answer = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    
    air.push(make_pair(1, 1));
    visited[1][1] = true;
    // 시간 단위
    while(true) {
        // 외부 공기 채우기 진행
        while(!air.empty()) {
            pair<int, int> now = air.front();
            air.pop();

            for(int i = 0; i < 4; i++) {
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];

                // Scope 밖이면 패스
                if(nx < 1 || nx > N || ny < 1 || ny > M) {
                    continue;
                }

                // 공기이면서, 외부 공기 판정을 아직 받지 못한 경우 
                if(visited[nx][ny] == 0 && graph[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    air.push(make_pair(nx, ny));
                }
            }
        }

        // 치즈 녹이기 진행
        int cheese_size = cheese.size();
        for(int i = 0; i < cheese_size; i++) {
            pair<int, int> now = cheese.front();
            cheese.pop();

            int cnt = 0;
            for(int d = 0; d < 4; d++) {
                int nx = now.first + dx[d];
                int ny = now.second + dy[d];

                // 해당 면이 외부공기와 맞닿아 있다면
                if(visited[nx][ny]) {
                    cnt++;
                }
            }

            // 외부 공기와 맞닿은 면이 1개 이하라면 치즈 유지
            if(cnt < 2) {
                cheese.push(now);
            } else {
                temp.push(now);
            }
        }

        while(!temp.empty()) {
            pair<int, int> now = temp.front();
            temp.pop();

            visited[now.first][now.second] = 1;
            air.push(now);
        }

        answer ++;

        // 더 이상 녹을 치즈가 없을 경우, 반복문 탈출
        if(cheese.size() == 0) {
            break;
        }
    }

    cout << answer << endl;
}