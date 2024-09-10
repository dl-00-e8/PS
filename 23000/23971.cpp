#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int H, W, N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> N >> M;

    cout << ((H - 1) / (N + 1) + 1) * ((W - 1) / (M + 1) + 1) << endl;

    return 0;
}