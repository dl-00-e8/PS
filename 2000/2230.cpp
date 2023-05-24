#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll n, m;
ll arr[100001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}

void solve() {
    ll answer = 2000000001;
    ll end = 1;

    sort(arr, arr + n);

    // 투 포인터
    for(ll start = 1; start < n + 1; start++) {        
        while(end < n && abs(arr[start] - arr[end]) < m) {
            end++;
        }

        if(abs(arr[start] - arr[end]) >= m) {
            // cout << start << " " << end << endl;
            answer = min(answer, abs(arr[start] - arr[end]));
        }
    }

    cout << answer << endl;
}