#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int a, b, c;
int dp[21][21][21];
bool already[21][21][21];
int solve(int a, int b, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    memset(already, 0, sizeof(already));
    while(true) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << endl;
    }

    return 0;
}

int solve(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if(a > 20 || b > 20 || c > 20) {
        return solve(20, 20, 20);
    }

    if(already[a][b][c]) {
        return dp[a][b][c];
    }

    already[a][b][c] = true;

    if(a < b && b < c) {
        return dp[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c -1) - solve(a, b - 1, c);
    }
    else {
        return dp[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c -1);
    }
}