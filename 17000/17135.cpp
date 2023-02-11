#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, d, enemy;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[17][17];
int graphCopy[17][17];
pair<int, int> dfs(int x, int y, int d);
int defense(int a, int b, int c);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    enemy = 0;

    cin >> n >> m >> d;
    for(int i = 1; i < n + 1; i ++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 1) {
                enemy++;
            }
        }
    }

    solve();

    return 0;
}

pair<int, int> dfs(int x, int y, int d) {
    pair<int, pair<int, int>> kill = {987654321 ,{-1, m + 1}}; // 가장 왼쪽일 경우를 찾아내기 위해
    stack<pair<int, pair<int, int>>> s;

    s.push({0, {x, y}});
    while(!s.empty()) {
        int x = s.top().second.first;
        int y = s.top().second.second;
        int dist = s.top().first;

        s.pop();

        // 공격 사거리 초과하면 안 되므로
        if(dist == d) {
            continue;
        }

        for(int i = 0;  i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx > n || ny < 0 || ny > m) {
                continue;
            }

            if(graphCopy[nx][ny] == 0) {
                s.push({dist + 1, {nx, ny}});
            }
            else if(graphCopy[nx][ny] == 1) {
                if(kill.first > dist + 1) {
                    kill.first = dist + 1;
                    kill.second = {nx, ny};
                }
                else if(kill.first == dist + 1) {
                    if(kill.second.second > ny) {
                        kill.second = {nx, ny};
                    }
                }
            }

            
        }
    }

    return kill.second;
}

int defense(int a, int b, int c) {
    int result, nowEnemy;
    queue<pair<int, int>> q;

    result = 0;
    nowEnemy = enemy;

    // 복사
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            graphCopy[i][j] = graph[i][j];
        }
    }

    // 남아있는 적이 없을 때까지
    while(nowEnemy > 0) {
        // 궁수의 공격 (공격할 적 정보 파악)
        queue<pair<int, int>> q;
        q.push(dfs(n + 1, a, d));
        q.push(dfs(n + 1, b, d));
        q.push(dfs(n + 1, c, d));

        // 공격하게 될 적 제거
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(x == -1) {
                continue;
            }

            //이미 제거되었을 경우 제외
            if(graphCopy[x][y] == 1) {
                graphCopy[x][y] = 0;
                nowEnemy--;
                result++;
            }
        }

        // 적의 이동
        for(int i = n; i > 0; i--) {
            for(int j = m; j > 0; j--) {
                if(graphCopy[i][j] && i != n) {
                    graphCopy[i + 1][j] = 1;
                    graphCopy[i][j] = 0;
                }
                else if(graphCopy[i][j] && i == n) {
                    graphCopy[i][j] = 0;
                    nowEnemy--;
                }
            }
        }
    }

    return result;
}

void solve() {
    int answer = 0;

    // 궁수 배치
    for(int i = 1; i < m + 1; i++) {
        for(int j = i + 1; j < m + 1; j++) {
            for(int k = j + 1; k < m + 1; k++) {
                answer = max(answer, defense(i, j, k));
            }
        }   
    }

    cout << answer << endl;
}

/*
1.
궁수 3명을 놓아야 함 -> Brute Force
궁수를 놓는 시간 복잡도 계산: 5C3 = 10
-> 문제를 똑바로 읽을 것

2.
예제 6번 결과 12로 나오는 문제 -> 정답 14 (when 1, 4, 5에 궁수 위치)


문제: https://www.acmicpc.net/problem/17135
*/