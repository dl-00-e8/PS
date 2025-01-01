#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M, answer = 0;
vector<int> graph[2001];
bool visited[2001];
void dfs(int idx, int now, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, 0, 4);
        if(answer) {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}

void dfs(int idx, int now, int depth) {
    visited[idx] = 1;

    if(now >= depth) {
        answer = 1;
        return;
    }

    for(int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];
        if(!visited[next]) {
            dfs(next, now + 1, depth);
        }
    }

    visited[idx] = 0;
}