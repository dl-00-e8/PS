#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define MAX 9223372036854775807

int t, n;
ll sumX, sumY;
double result;
vector<pair<int, int>> graph;
void dfs(ll sumX, ll sumY, int nowIdx, int cnt);
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        graph.clear();
        result = MAX;
        sumX = 0;
        sumY = 0;
        
        cin >> n;

        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            graph.push_back({a, b});
            sumX += a;
            sumY += b;
        }

        for(int i = 0; i <= n / 2; i++) {
            dfs(sumX, sumY, i, 1);
        }

        cout << fixed;
        cout.precision(15);
        cout << sqrt(result) << endl;
    }

    return 0;       
}

void dfs(ll sumX, ll sumY, int nowIdx, int cnt) {
    ll nowSumX = sumX - (2 * graph[nowIdx].first);
    ll nowSumY = sumY - (2 * graph[nowIdx].second);

    if(cnt == n / 2) {
        result = min(result, pow(nowSumX, 2) + pow(nowSumY, 2));
        
        return;
    }

    // dfs ¿¬°á
    for(int i = nowIdx + 1; i < n; i++) {
        dfs(nowSumX, nowSumY, i, cnt + 1);
    }
}