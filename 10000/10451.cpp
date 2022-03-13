#include <bits/stdc++.h>

using namespace std;

#define enld "\n"

int t, n;
vector<int> graph;
int visited[1001];
int dfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(visited, 0, sizeof(visited));

        cin >> n;
        for(int i = 0; i < n; i++) {
            int input;
            cin >> input;
            graph.push_back(input);
        }

        cout << dfs() << endl;

        vector<int>().swap(graph);
    }

    return 0;
}

int dfs() {
    int areaNum = 1;

    for(int i = 1; i < n + 1; i++) {
        if(visited[i] != 0) {
            continue;
        }

        queue<int> q;
        
        q.push(i);
        visited[i] = areaNum;
        while(!q.empty()) {
            int now = q.front();
            q.pop();

            if(visited[graph[now - 1]] == 0) {
                visited[graph[now - 1]] = areaNum;
                q.push(graph[now - 1]);
            }
        }

        areaNum++;
    }

    return areaNum - 1;
}