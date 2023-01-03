#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<int> straw;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        straw.push_back(input);
    }

    solve();

    return 0;
}

void solve() {
    bool escape = false;
    
    sort(straw.begin(), straw.end(), greater<int>());

    for(int i = 2; i < n; i++) {
        if(straw[i - 1] + straw[i] > straw[i - 2]) {
            cout << straw[i] + straw[i - 1] + straw[i - 2] << endl;
            escape = true;
            break;
        }
    }

    if(!escape) {
        cout << -1 << endl;
    }
}