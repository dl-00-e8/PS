#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, result;
vector<int> graph[10001];
bool visited[10001];
int bfs(int start);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    solve();
}

int bfs(int start) {
    int cnt = 1;
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            if(!visited[graph[now][i]]) {
                cnt++;
                visited[graph[now][i]] = true;
                q.push(graph[now][i]);
            }
        }
    }

    return cnt;
}

void solve() {
    vector<int> answer;

    result = 0;
    for(int i = 1; i < n + 1; i++) {
        memset(visited, 0, sizeof(visited));
        
        int temp = bfs(i);
        
        if(temp > result) {
            vector<int>().swap(answer); // vector clear
            answer.push_back(i);
            result = temp;
        }
        else if(temp == result) {
            answer.push_back(i);
        }
        else {
            continue;
        }
    }

    sort(answer.begin(), answer.end(), less<int>());
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}