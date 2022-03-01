#include <bits/stdc++.h>

using namespace std;

#define enld "\n"

int n, m;
set<int> card;
vector<int> check;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        card.insert(input);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int input;
        cin >> input;
        check.push_back(input);
    }

    solve();

    return 0;
}

void solve() {
    for(int i = 0; i < m; i++) {
        if(card.find(check[i]) != card.end()) {
            cout << 1 << " ";
        }
        else { 
            cout << 0 << " ";
        }
    }

}