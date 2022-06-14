#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int t, x, y;
int solve(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {       
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }

    return 0;
}

int solve(int x, int y) {
    ll num = 0;

    while(pow(num, 2) <= y - x) {
        num++;
    }
    num--;

    if(y - x == pow(num, 2)) {
        return 2 * num - 1;
    }
    else if(y - x < (pow(num, 2) + pow(num + 1, 2)) / 2) {
        return 2 * num;
    }
    else {
        return 2 * (num + 1) - 1;
    }

    return 0;
}