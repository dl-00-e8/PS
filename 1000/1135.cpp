#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<pair<int, int>> call[51];
int dfs(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if(input != -1) {
            call[input].push_back({0, i});
        }
    }

    cout << dfs(0) << endl;

    return 0;
}

int dfs(int x) {
    int cnt = 0;

    for(int i = 0; i < call[x].size(); i++) {
        call[x][i].first = 1 + dfs(call[x][i].second);
    }

    sort(call[x].begin(), call[x].end(), greater<pair<int, int>>());

    for(int i = 0; i < call[x].size(); i++) {
        cnt = max(cnt, call[x][i].first + i);
    }

    return cnt;
}