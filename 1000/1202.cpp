#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, k;
vector<pair<int, int>> j;
priority_queue<int, vector<int>, greater<int>> bag;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        j.push_back({m, v});
    }
    for(int i = 0; i < k; i++) {
        int input;
        cin >> input;
        bag.push(input);
    }

    solve();

    return 0;
}

void solve() {
    int idx = 0;
    ll result = 0;
    priority_queue<int, vector<int>, less<int>> jew;

    sort(j.begin(), j.end(), less<pair<int, int>>());

    while(!bag.empty()) { 
        for(; idx < n; idx++) {
            if(j[idx].first <= bag.top()) {
                jew.push(j[idx].second);
            }
            else {
                break;
            }
        }

        if(!jew.empty()) {
            result += jew.top();
            jew.pop();
        }

        bag.pop();
    }

    cout << result << endl;
}