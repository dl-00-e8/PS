#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, k, x;
int a[100001];
int rate[100001];
int preSum[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(rate, 0, sizeof(rate));
    memset(preSum, 0, sizeof(preSum));

    cin >> n >> m >> k >> x;
    rate[0] = x;
    preSum[0] = 0;
    for(int i = 1; i < n + 1; i++) {
        cin >> a[i];
        rate[i] = rate[i - 1] + a[i];

        if(rate[i] < k) {
            preSum[i] = preSum[i - 1] + 1;
            //cout << preSum[i] << " ";
        }
        else {
            preSum[i] = preSum[i - 1];
            // cout << preSum[i] << " ";
        }
    }
    // cout << endl;

    // Output
    for(int i = 0; i < m; i++) {
        int l, r, result;
        cin >> l >> r;
        cout << preSum[r - 1] - preSum[l - 1] << endl;
    }

    return 0;
}