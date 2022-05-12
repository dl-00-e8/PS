#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int a[51];
int b[51];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    solve();

    return 0;
}

void solve() {
    int result = 0;
    int mulMax = 0;

    for(auto now : b) {
        int mulNow = 0;

        while(now != 0) {
            if(now % 2 == 0) {
                now /= 2;
                mulNow++;
            }
            else {
                now--;
                result++;
            }
        }

        mulMax = max(mulMax, mulNow);
    }

    result += mulMax;

    cout << result << endl;
}

/*
하나씩 하고
동시에 2배 곱해지는 거는 max값만 별도로 계산
*/