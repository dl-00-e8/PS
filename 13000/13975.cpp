#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int t, k;
priority_queue<ll, vector<ll>, greater<ll>> pq;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> k;
        for(int i = 0; i < k; i++) {
            int input;
            cin >> input;
            pq.push(input);
        }

        solve();
    }

    return 0;
}

void solve() {
    ll a, b, input, result;
    priority_queue<ll, vector<ll>, greater<ll>> empty;

    result = 0;
    while(true) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        
        input = a + b;
        result += input;

        pq.push(input);

        if(pq.size() == 1) {
            break;
        }
    }

    cout << result << endl;

    // 빈 우선순위 큐로 교환
    swap(pq, empty);
}