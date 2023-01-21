#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, len;
int dp[10001];
vector<pair<int, int>> graph[10001];
// bool compare(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(int), INF);

    cin >> n >> len;
    for(int i = 0; i < n; i++) {
        int s, d, l;
        cin >> s >> d >> l;
        graph[d].push_back({s, l});
    }

    solve();

    return 0;
}

// bool compare(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
//     if(a.first.first == b.first.first) {
//         return a.first.second < b.first.second;
//     }

//     return a.first.first < b.first.first;
// }

void solve() {
    dp[0] = 0;
    for(int i = 1; i < 10001; i++) {
        if(graph[i].size() == 0) {
            dp[i] = dp[i - 1] + 1;
            continue;
        }

        for(int j = 0; j < graph[i].size(); j++) {
            int start = graph[i][j].first;
            int cost = graph[i][j].second;

            dp[i] = min({dp[i], dp[i - 1] + 1, dp[start] + cost});
        }
    }

    // for(int i = 1; i < 10001; i++) {
    //     cout << dp[i] << endl;
    // }

    cout << dp[len] << endl;
}