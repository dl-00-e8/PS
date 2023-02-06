#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int h[1000001];
int arrow[1000001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(h, 0, sizeof(h));
    memset(arrow, 0, sizeof(arrow));

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> h[i];
    }

    solve();

    return 0;
}

void solve() {
    int answer = 0;

    for(int i = 1; i < n + 1; i++) {
        int now = h[i];

        if(arrow[now] == 0) {
            arrow[now - 1]++;
        }
        else {
            arrow[now - 1]++;
            arrow[now]--;
        }
    }

    for(int i = 0; i < 1000001; i++) {
        if(arrow[i]) {
            answer += arrow[i];
        }
    }

    cout << answer << endl;
}