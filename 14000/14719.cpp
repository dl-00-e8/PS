#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int H, W;
int height[501];
int rain[501];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(height, 0, sizeof(height));
    memset(rain, 0, sizeof(rain));

    cin >> H >> W;
    for(int i = 0; i < W; i++) {
        cin >> height[i];
    }

    solve();

    return 0;
}

void solve() {
    int answer = 0;

    // 좌우 양끝은 물이 고일 수가 없음
    int idx = 0;
    for(int i = 1; i < W - 1; i++) {
        int left = 0, right = 0;

        for(int j = 0; j < i; j++) {
            left = max(left, height[j]);
        }
        for(int j = i + 1; j < W; j++) {
            right = max(right, height[j]);
        }

        answer += max(0, min(left, right) - height[i]);
    }

    cout << answer << endl;
}