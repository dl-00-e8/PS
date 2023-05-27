#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k;
int arr[100001];
int preSum[100001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(preSum, 0, sizeof(preSum));

    cin >> n >> k;
    for(int i = 1; i < n + 1; i++) {
        cin >> arr[i];
        preSum[i] = preSum[i - 1] +  arr[i];
    }

    solve();

    return 0;
}

void solve() {
    int last = 0;
    int answer = -1000000000;

    for(int start = 0; start + k < n + 1; start++) {
        answer = max(answer , preSum[start + k] - preSum[start]);
    }

    cout << answer << endl;
}