#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, m;
int graph[501][501]; 
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&graph[0][0], &graph[500][501], INF);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    solve();

    return 0;
}

void solve() {
    int result = 0;

    /* 
    순서를 파악할 수 있다는 것은 
    해당 위치로 이동이 가능해진다는 의미와 동일하게 사용될 수 있음
    그렇기에, floyd-warshall로 모든 노드에서 다른 모든 노드까지의
    최단거리를 갱신해서 전부 다 갱신되어 있는 상황일 경우 카운팅
    */
    for(int k = 1; k < n + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        int cnt = 0;
       for(int j = 1; j < n + 1; j++) {
           if(graph[i][j] != INF || graph[j][i] != INF) {
               cnt++;
           }
       }
       if(cnt == n - 1) {
            result++;
       }
    }

    cout << result << endl;
}