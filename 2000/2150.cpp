#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int v, e;
stack<int> s;
vector<int> temp;
vector<int> graph[10001];
vector<int> reverseGraph[10001];
bool visited[10001];
vector<vector<int> > answer;
void dfs(int x);
void reverseDfs(int x);
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }
    
    // 정방향 DFS 진행
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i < v + 1; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    // 역방향 DFS 진행
    memset(visited, 0, sizeof(visited));
    while(!s.empty()) {
        int now = s.top();
        s.pop();

        if(visited[now]) {
            continue;
        }
        
        reverseDfs(now);

        // 정렬 후 삽입
        sort(temp.begin(), temp.end(), less<int>());
        answer.push_back(temp);

        // temp 배열 초기화
        vector<int>().swap(temp);
    }

    output();

    return 0;
}

void dfs(int x) {
    visited[x] = true;

    for(int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];
        
        if(!visited[next]) {
            dfs(next);
        }
    }

    s.push(x);
}

void reverseDfs(int x) {
    visited[x] = true;

    temp.push_back(x);

    for(int i = 0; i < reverseGraph[x].size(); i++) {
        int next = reverseGraph[x][i];

        if(!visited[next]) {
            reverseDfs(next);
        }
    }
}

void output() {
    cout << answer.size() << endl;

    sort(answer.begin(), answer.end(), less<vector<int> >());

    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << -1 << endl;
    }
}