#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321
#define ll long long

int n, m, q;
vector<pair<ll, ll>> bully;
pair<ll, ll> graph[501][501]; // first : 통행시간, second : 괴롭히는 Max 시간
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 1; i < n + 1; i++) {
        int input;
        cin >> input;
        bully.push_back({input, i});
    }

    // graph 비용 {INF, INF}로 초기화
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(i == j) {
                graph[i][j] = {0, bully[i - 1].first};
            }
            graph[i][j] = {INF, INF};
        }
    }

    for(int i = 0; i < m; i++) {
        ll a, b, d, maxNum;
        cin >> a >> b >> d;
        maxNum = max(bully[a - 1].first, bully[b - 1].first);
        graph[a][b] = {d, maxNum}; // first : 거리, second : 멍멍이의 최대 괴롭힘 시간 갱신
        graph[b][a] = {d, maxNum};
    }

    solve();

    while(q--) {
        int s, t;
        cin >> s >> t;
        if(graph[s][t].first == INF) {
            cout << -1 << endl;
        }
        else {
            cout << graph[s][t].first + graph[s][t].second << endl;
        }
    }

    return 0;
}

void solve() {
    // 정점 정렬
    sort(bully.begin(), bully.end(), less<pair<ll, ll>>());

    for(auto k : bully) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                ll val1, val2;
                val1 = graph[i][j].first + graph[i][j].second;
                val2 = graph[i][k.second].first + graph[k.second][j].first + max(graph[i][k.second].second, graph[k.second][j].second);

                if(val1 > val2) {
                    graph[i][j].first = graph[i][k.second].first + graph[k.second][j].first;
                    graph[i][j].second = max(graph[i][k.second].second, graph[k.second][j].second);
                }
                else if(val1 == val2) {
                    if(graph[i][j].second < max(graph[i][k.second].second, graph[k.second][j].second)) {
                        graph[i][j].first = graph[i][k.second].first + graph[k.second][j].first;
                        graph[i][j].second = max(graph[i][k.second].second, graph[k.second][j].second);
                    }
                }
            }
        }
    }
}