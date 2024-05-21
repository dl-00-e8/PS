#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
vector<int> tree[100001];
int visited[100001];
void bfs(int start);
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 방문 여부 조회 배열을 -1로 초기화
    memset(visited, -1, sizeof(visited));

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;

        cin >> a >> b;
        tree[b].push_back(a);
        tree[a].push_back(b);
    }
    
    bfs(1);
    output();

    return 0;
}

void bfs(int start) {
    queue<int> q;

    q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int idx = 0; idx < tree[now].size(); idx++) {
            int next = tree[now][idx];

            if(visited[next] == -1) {
                visited[next] = now;
                q.push(next);
            }
        }
    }
}

void output() {
    for(int i = 2; i < N + 1; i++) {
        cout << visited[i] << endl;
    }
}