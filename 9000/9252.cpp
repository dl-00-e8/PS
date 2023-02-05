#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string a, b;
vector<char> answer;
// int dx[] = {-1, 0, -1};
// int dy[] = {0, -1, -1};
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

// void find(int x, int y) {
//     int mx, my;
//     bool check = true;

//     if(dp[x][y] == 0) {
//         return ;
//     }

//     if(x < 0 || y < 0) {
//         return ;
//     }

//     for(int i = 0; i < 2; i++) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if(dp[nx][ny] == dp[x][y]) {
//             check = false;
//             find(nx, ny);
//         }
//     }

//     if(check) {
//         answer.push_back(a[x - 1]);
//         find(x - 1, y - 1);
//     }
// }

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

    // find(a.size(), b.size());

    int x = a.size();
    int y = b.size();
    while(dp[x][y] != 0) {
        if(dp[x][y] == dp[x - 1][y]) {
            x--;
        }
        else if(dp[x][y] == dp[x][y - 1]) {
            y--;
        }
        else {
            answer.push_back(a[x - 1]);
            x--;
            y--;
        }
    }

    cout << result << endl;
    for(int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i];
    }
    cout << endl;
}