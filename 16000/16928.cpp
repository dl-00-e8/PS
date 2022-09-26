#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int ladder[101];
int snake[101];
int visited[101];
void bfs(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ladder, 0, sizeof(ladder));
    memset(snake, 0, sizeof(snake));
    fill(&visited[0], &visited[0] + sizeof(visited) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    bfs(1);

    cout << visited[100] << endl;

    return 0;
}

void bfs(int start) {
    int next;
    queue<int> q;

    q.push(start);
    visited[start] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        // 주사위 던지기
        for(int i = 1; i <= 6; i++) {
            next = now + i;
        
            if(next > 100) {
                continue;
            }

            // 사다리 또는 뱀 존재 시, dest 변경
            if(ladder[next] != 0) {
                next = ladder[next];
            }
            else if(snake[next] != 0) {
                next = snake[next];
            }
            
            // 최솟값 갱신
            if(visited[next] > visited[now] + 1) {
                visited[next] = visited[now] + 1;
                
                q.push(next);
            }
        }
    }
}