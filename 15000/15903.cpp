#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        pq.push(input);
    }

    solve();

    return 0;
}

void solve() {
    ll result = 0;

    for(int i = 0; i < m; i++) {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();

        pq.push(x + y);
        pq.push(x + y);
    }

    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result << endl;
}