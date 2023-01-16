#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int input[100001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(input, 0, sizeof(input));

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    solve();

    return 0;
}

void solve() {
    int ret = 0;
    int cnt = 0;
    int temp = 0;
    int result = 0;

    for(int i = 0; i < n; i++) {
        if(input[i] == 1) {
            temp = -1;
        }
        else {
            temp = 1;
        }

        cnt += temp;
        cnt = max(0, cnt);
        ret = max(ret, cnt);
    }
    result = max(result, ret);

    ret = 0;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(input[i] == 1) {
            temp = 1;
        }
        else {
            temp = -1;
        }

        cnt += temp;
        cnt = max(0, cnt);
        ret = max(ret, cnt);
    }

    result = max(result, ret);

    cout << result << endl;
}