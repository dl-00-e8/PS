#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
char input[500001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    solve();

    return 0;
}

void solve() {
    if(n == 1) {
        cout << 1 << endl;

        return ;
    }

    int cnt = 0;
    int rCnt = 0;
    int bCnt = 0;
    if(input[0] == 'R') {
        rCnt++;
    }
    else {
        bCnt++;
    }

    for(int i = 1; i < n; i++) {
        if(input[i] != input[i - 1]) {
            cnt++;

            if(input[i] == 'R') {
                rCnt++;
            }
            else {
                bCnt++;
            }
        }        
    }
    
    // cout << cnt << " " << rCnt << " " << bCnt << endl;
    cout << min({cnt, rCnt, bCnt}) + 1 << endl;
    
}