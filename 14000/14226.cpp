#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int S;
int visited[1002][1002];
void bfs(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(int), INF);

    cin >> S;

    bfs(S);

    return 0;
}

void bfs(int x) {
    queue<pair<int, int>> q;

    q.push({1, 0});
    visited[1][0] = 0;
    while(!q.empty()) {
        int now = q.front().first;
        int cp = q.front().second;

        q.pop();

        if(now == S) {
            break;
        }

        if(now < 0 || now > 2000) {
            continue;
        }
        
        if(visited[now][cp] + 1 < visited[now][now]) {
            visited[now][now] = visited[now][cp] + 1;
            q.push({now, now});
        }

        if(now - 1 >= 0 && visited[now][cp] + 1 < visited[now - 1][cp]) {
            visited[now - 1][cp] = visited[now][cp] + 1;
            q.push({now - 1, cp});
        }

        if(now + cp < 1001 && visited[now][cp] + 1 < visited[now + cp][cp]) {
            visited[now + cp][cp] = visited[now][cp] + 1;
            q.push({now + cp, cp});
        }
    }

    int answer = INF;
    for(int i = 0; i < 1001; i++) {
        answer = min(answer, visited[x][i]);
    }
    cout << answer << endl;
}