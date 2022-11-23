#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
string input;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> input;

    solve();

    return 0;
}

void solve() {
    int result = 100000;
    int cnt[5];

    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < input.size(); i++) {
        if(input[i] == 'H') {
            cnt[0]++;
        }
        else if(input[i] == 'I') {
            cnt[1]++;
        }
        else if(input[i] == 'A') {
            cnt[2]++;
        }
        else if(input[i] == 'R') {
            cnt[3]++;
        }
        else if(input[i] == 'C') {
            cnt[4]++;
        }
    }

    for(int i = 0; i < 5; i++) {
        result = min(result, cnt[i]);
    }
    
    cout << result << endl;
}