#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 10000
#define ll long long

int n;
ll endPoint, result;
bool visited[MAX + 1];
ll diameter[MAX + 1];
vector<pair<int, int>> graph[MAX + 1];
void dfs(int x);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    solve();

    return 0;
}

void dfs(int x) {
    stack<int> s;

    memset(visited, 0, sizeof(visited));
    memset(diameter, 0, sizeof(diameter));

    s.push(x);
    visited[x] = true;
    while(!s.empty()) {
        int now = s.top();

        if(diameter[now] > result) {
            result = diameter[now];
            endPoint = now;
        }

        s.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            ll cost = graph[now][i].second;

            if(diameter[next] < diameter[now] + cost && !visited[next]) {
                visited[next] = true;
                diameter[next] = diameter[now] + cost;
                
                s.push(next);
            }
        }
    }

}

void solve() {

    result = 0;
    endPoint = 1;
    dfs(1);

    result = 0;
    dfs(endPoint);

    cout << result << endl;
}