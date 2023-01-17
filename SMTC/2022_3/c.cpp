#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, m, c;
int w[17][17];
int a[1001];
int b[1001];
ll dp[1001][1001];
ll solve(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(w, 0, sizeof(w));
    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> c;
    for(int i = 1; i < c + 1; i++) {
        for(int j = 1; j < c + 1; j++) {
            cin >> w[i][j];
        }
    }
    for(int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < m + 1; i++) {
        cin >> b[i];
    }

    cout << solve(1, 1) << endl;

    return 0;
}

ll solve(int x, int y) {
    if(x == n + 1 || y == m + 1) {
        return 0;
    }

    ll temp = dp[x][y];

    if(temp == -1) {
        temp = 0;
        temp = max({w[a[x]][b[y]] + solve(x + 1, y + 1), solve(x, y + 1), solve(x + 1, y)});
    }

    return dp[x][y] = temp;
}