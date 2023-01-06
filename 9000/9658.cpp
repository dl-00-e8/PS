#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dp[1001][3];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;

    if(n % 7 == 1 || n % 7 == 3) {
        cout << "CY" << endl;
    }
    else {
        cout << "SK" << endl;
    }

    return 0;
}

/*
게임 이론에 대한 고찰
https://www.acmicpc.net/board/view/26161

돌 1개
-> 무조건 상근 패배 (가져가야 하므로)

돌 2개
상근 1개 -> 창영 패배

돌 3개
상근 1개 -> 창영 1개 -> 상근 패배

돌 4개
상근 3개 -> 창영 패배

돌 5개
상근 4개 -> 창영 패배

돌 6개
상근 3개 -> 창영 1개 -> 상근 1개 -> 창영 패배

돌 7개
상근 4개 -> 창영 1개 -> 상근 1개 -> 창영 패배

돌 8개
상근 4개 -> 창영 3개 -> 상근 패배
상근 3개 -> 창영 4개 -> 상근 패배

7개를 기준으로 돌림 노래 반복
*/
