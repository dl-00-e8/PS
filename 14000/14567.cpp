#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int indigree[1001];
int result[1001];
vector<int> graph[1001];
void topologySort();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(indigree, 0, sizeof(indigree));
    memset(result, 0, sizeof(result));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;
        graph[a].push_back(b);
        indigree[b]++;
    }

    topologySort();


    return 0;
}

void topologySort() {
    queue<int> q;

    // Queue Push
    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            q.push(i);
            result[i] = 1;
        }
    }

    // Algorithm
    while(!q.empty()) {
        int now = q.front();

        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next= graph[now][i];

            indigree[next]--;
            if(indigree[next] == 0) {
                q.push(next);
                result[next] = result[now] + 1;
            }
        }
    }

    // Output
    for(int i = 1; i < n + 1; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}