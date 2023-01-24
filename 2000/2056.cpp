#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dp[10001];
int work[10001];
int indigree[10001];
vector<int> graph[10001];
void topologySort();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    memset(work, 0, sizeof(work));
    memset(indigree, 0, sizeof(indigree));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> work[i];

        int cnt;
        cin >> cnt;
        indigree[i] = cnt;
        for(int j = 0; j < cnt; j++) {
            int input;
            cin >> input;
            graph[input].push_back(i);
        }
    }

    topologySort();

    return 0;
}

void topologySort() {
    queue<int> q;

    // 진입차수가 0인 노드 큐 삽입
    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();

        q.pop();

        dp[now] += work[now];
        for(int i = 0 ; i < graph[now].size(); i++) {
            int next = graph[now][i];

            indigree[next]--;
            dp[next] = max(dp[next], dp[now]);

            if(indigree[next] == 0) {
                q.push(next);
            }
        }
    }

    int result = 0;
    for(int i = 1; i < n + 1; i++) {
        result = max(result, dp[i]);
        //cout << dp[i] << " ";
    }
    //cout << endl;
    cout << result << endl;
}