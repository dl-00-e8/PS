#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<pair<int, int>> v;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    solve();

    return 0;
}

void solve() {
    int start, end;
    int result = 0;

    sort(v.begin(), v.end(), less<pair<int, int>>());

    if(n == 1) {
        cout << v[0].second - v[0].first << endl;
        return ;
    }

    start = v[0].first;
    end = v[0].second;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].first <= end) {
            end = max(end, v[i].second);
        }
        else {
            result += end - start;

            start = v[i].first;
            end = v[i].second;            
        }
    }

    result += end - start;

    cout << result << endl;
}