#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string a, b;
vector<char> answer;
int dx[] = {-1, 0};
int dy[] = {0, -1};
int dp[1001][1001];
void find(int x, int y);
void solve();

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> a >> b;

    solve();

    return 0;
}

void find(int x, int y) {
    int now = dp[x][y];
    bool check = true;

    if(now == 0) {
        return ;
    }

    if(x < 0 || y < 0) {
        return ;
    }

    for(int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
    }
}

void solve() {
    int result = 0;

    for(int i = 1; i < a.size() + 1; i++) {
        for(int j = 1; j < b.size() + 1; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

            result = max(result, dp[i][j]);
        }
    }

    for(int i = 1; i < a.size() + 1; i++) {
        for(int j = 1; j < b.size() + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    find(a.size(), b.size());

    cout << result << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    cout << endl;
}