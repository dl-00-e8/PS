#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, k, m, p;
vector<int> graph[1001];
int indigree[1001];
pair<int, bool> strahler[1001];
int topologySort();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(graph, 0, sizeof(graph));
        memset(indigree, 0, sizeof(indigree));
        memset(strahler, 0, sizeof(strahler));

        cin >> k >> m >> p;
        for(int i = 0; i < p; i++) {
            int a, b;
            cin >> a >> b;
            
            graph[a].push_back(b);
            indigree[b]++;
        }

        cout << k << " " << topologySort() << endl;
    }

    return 0;
}

int topologySort() {
    int answer = 1;
    queue<int> q;

    for(int i = 1; i < m + 1; i++) {
        if(indigree[i] == 0) {
            q.push(i);
            strahler[i].first = 1;
        }
    }

    while(!q.empty()) {
        int now = q.front();
        
        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if(strahler[next].first < strahler[now].first) {
                strahler[next].first = strahler[now].first;
                strahler[next].second = true;
            }
            else if(strahler[next].first == strahler[now].first) {
                if(strahler[next].second) {
                    strahler[next].first++;
                    strahler[next].second = false;
                }
                else {
                    strahler[next].second = true;
                }
            }

            answer = max(answer, strahler[next].first);

            if(--indigree[next] == 0) {
                q.push(next);
            }
        }
    }

    return answer;
}