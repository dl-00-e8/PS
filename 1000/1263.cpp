#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
bool compare(pair<int, int> a, pair<int, int> b);
vector<pair<int, int>> data;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        data.push_back({t, s});
    }

    solve();

    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first > b.first;
    }

    return a.second > b.second;
}

void solve() {
    int now;
    sort(data.begin(), data.end(), compare);

    /*
    for(int i = 0; i < n; i++) {
        cout << data[i].first << " " << data[i].second << endl;
    }
    */

    now = data[0].second;
    for(int i = 1; i < n; i++) {
        if(now - data[i - 1].first >= data[i].second) {
            now = data[i].second;
        }
        else {
            now = now - data[i - 1].first;
        }

        // cout << now << endl;
    }

    now -= data[n - 1].first;
    if(now < 0) {
        cout << -1 << endl;
    }
    else {
        cout << now << endl;
    }
}
