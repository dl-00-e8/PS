#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, l;
ll box[200001];
ll preSum[200001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(box, 0, sizeof(box));
    memset(preSum, 0, sizeof(preSum));

    cin >> n >> l;
    for(int i = 1; i < n + 1; i++) {
        cin >> box[i];
        preSum[i] = preSum[i - 1] + box[i];
    }

    solve();

    return 0;
}

void solve() {
    bool result = true;
    ll minRange, maxRange;

    for(int i = n - 1; i > 0; i--) {
        double sum = double((preSum[n] - preSum[i])* (1.0) / (n - i)) ;

        
        minRange = box[i] - l;
        maxRange = box[i] + l;

        if(minRange < sum && sum < maxRange) {
            continue;
        }
        else {
            result = false;
            break;
        }
    }

    if(result) {
        cout << "stable" << endl;
    }
    else {
        cout << "unstable" << endl;
    }
}