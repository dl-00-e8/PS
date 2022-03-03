#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int t, n;
int stock[1000001];
ll solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> stock[i];
        }
        cout << solve() << endl;
    }

    return 0;
}

ll solve() {
    ll maxNum = 0;
    ll result = 0;

    for(int i = n - 1; 0 <= i; i--) {
        if(stock[i] < maxNum) {
            result += (maxNum - stock[i]);
        }
        else {
            maxNum = stock[i];
        }
    }

    return result;
}