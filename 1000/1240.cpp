#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
vector<pair<int, int>> node[1001];
int visited[1001];
bool compare(pair<int, int> &a, pair<int, int> &b);
void dfs(int x, int dest);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }
    
    // sort
    for(int i = 1; i < n + 1; i++) {
        sort(node[i].begin(), node[i].end(), compare);
    }

    while(m--) {
        // default setting
        fill(&visited[0], &visited[0] + sizeof(visited)/sizeof(int), INF);
        
        int a, b;

        cin >> a >> b;

        visited[a] = 0;
        dfs(a, b);
        cout << visited[b] << endl;
    }

    return 0;
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

void dfs(int x, int dest) {
    for(int i = 0; i < node[x].size(); i++) {
        int next = node[x][i].first;
        int cost = node[x][i].second;

        if(visited[next] > visited[x] + cost) {
            visited[next] = visited[x] + cost;
            if(next == dest) {
                return ;
            }

            dfs(next, dest);
        }
    }

}