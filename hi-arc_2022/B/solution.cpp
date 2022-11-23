#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << solve() << endl;

    return 0;
}

int solve() {
    int result = 0;

    if(n == 1) {
        result = 0;
    }
    else {
        int temp = n*n;

        if(temp % 2 == 0) {
            result = temp / 2;
        }
        else {
            result = temp / 2 + 1;
        }

        
    }

    return result;
}