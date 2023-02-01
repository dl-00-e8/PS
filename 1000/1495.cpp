#include <bits/stdc++.h> 

using namespace std;

#define endl "\n"

int n, s, m;
int volume[51];
bool dp[51][1001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n >> s >> m;
    for(int i = 1; i < n + 1; i++) {
        cin >> volume[i];
    }

    solve();

    return 0;
}

void solve() {
    dp[0][s] = true;
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < m + 1; j++){
            if(dp[i - 1][j]){
                if(j + volume[i] <= m) {
                    dp[i][j + volume[i]] = true;
                } 

                if(j - volume[i] >= 0) {
                    dp[i][j - volume[i]] = true;
                }
            }
        }
    }

    int result = -1;
    for(int i = 0; i < m + 1; i++) {
        if(dp[n][i]) {
            result = max(result, i);
        }
    }
    
    cout << result << endl;
}