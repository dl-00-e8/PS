#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n, k, w;
int build[1001]; // 건물 짓는 비용
int indigree[1001]; // 진입차수
int result[1001]; // 출력 결과
vector<int> graph[1001]; // 간선 정보
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(build, 0, sizeof(build));
        memset(indigree, 0, sizeof(indigree));
        memset(result, 0, sizeof(result));
        for(int i = 0; i < 1001; i++) {
            graph[i].clear();
        }

        cin >> n >> k;
        for(int i = 1; i < n + 1; i++) {
            cin >> build[i];
        }
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indigree[y]++;
        }
        cin >> w;

        cout << solve() << endl;
    }

    return 0;
}

int solve() {
    // first : 현재 노드까지의 시간, second : idx
    priority_queue<int, vector<int>, greater<int>> pq;

    // 진입 차수가 0인 노드들을 pq에 삽입
    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            pq.push(i);
            result[i] = build[i];
        }
    }

    // toplogy sort 진행
    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();

        for(auto visit : graph[now]) {
            result[visit] = max(result[visit], result[now] + build[visit]);
            
            indigree[visit]--;
            if(indigree[visit] == 0) {
                pq.push(visit);
            }
        }
    }

    return result[w];
}