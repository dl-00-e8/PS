#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll a, b, c;
ll solve(ll a, ll b, ll c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << solve(a, b, c);

    return 0;
}

ll solve(ll a, ll b, ll c) {
    ll temp;
    
    // 지수가 1일 때
    if(b == 1) {
        return a % c;
    }

    temp = solve(a, b / 2, c);
    temp = temp * temp % c;

    // 지수가 짝수 일때
    if(b % 2 == 0) {
        return temp;
    }

    // 지수가 홀수 일때
    return temp * a % c;   
}