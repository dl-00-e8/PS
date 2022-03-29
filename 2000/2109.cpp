#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, maxIdx;
priority_queue<int, vector<int>, less<int>> pq[10001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    maxIdx = 0;
    for(int i = 0; i < n; i++) {
        int d, p;
        cin >> p >> d;
        pq[d].push(p);
        maxIdx = max(maxIdx, d);
    }

    if(n == 0) {
        cout << 0 << endl;
    }
    else {
        solve();
    }

    return 0;
}

void solve() {
    priority_queue<int, vector<int>, less<int>> maxNum;
    int result = 0;

    for(int i = maxIdx; i > 0; i--) {
        while(!pq[i].empty()) {
            maxNum.push(pq[i].top());
            pq[i].pop();
        }
        
        if(!maxNum.empty()) {
            result += maxNum.top();
            maxNum.pop();
        }
    }

    cout << result << endl;    
}