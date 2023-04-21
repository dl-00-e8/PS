#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, q;
vector<int> v;
int preSum[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(preSum, 0, sizeof(preSum));

    cin >> n >> q;
    for(int i = 1; i < n + 1; i++) {
        int input;

        cin >> input;

        v.push_back(input);
    }
    sort(v.begin(), v.end(), less<int>());
    for(int i = 1; i < n + 1; i++) {
        preSum[i] = v[i - 1] + preSum[i - 1];
    }

    while(q--) {
        int l, r;
        
        cin >> l >> r;
 
        cout << preSum[r] - preSum[l - 1] << endl;
    }

    return 0;
}