#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int tc, n, m, answer;
stack<int> s;
vector<int> temp;
bool visited[100001];
vector<int> graph[100001];
void dfs(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        
        // 초기화
        answer = 0;
        for(int i = 1; i < n + 1; i++) {
            vector<int>().swap(graph[i]);
        }

        // Input
        for(int i = 0; i < m; i++) {
            int x, y;

            cin >> x >> y;

            graph[x].push_back(y);
        }

        // Dfs
        memset(visited, 0, sizeof(visited));
        
        for(int i = 1; i < n + 1; i++) {
            if(visited[i]) {
                continue;
            }

            dfs(i);
        }

        // Reverse Dfs
        memset(visited, 0, sizeof(visited));

        while(!s.empty()) {
            int now = s.top();
            s.pop();

            if(visited[now]) {
                continue;
            }

            dfs(now);
            
            answer++;        
        }

        // Output
        cout << answer<< endl;
    }

    return 0;
}

void dfs(int x) {
    visited[x] = true;

    for(int i = 0; i < graph[x].size(); i++) {
        if(!visited[graph[x][i]]) {
            dfs(graph[x][i]);
        }
    }

    s.push(x);
}