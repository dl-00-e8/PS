#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, l, p;
vector<pair<int, int>> gas;
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        gas.push_back({a, b});
    }
    cin >> l >> p;

    cout << solve() << endl;

    return 0;
}

int solve() {
    int gasIdx, result; // gasIdx = 주유소 Idx, result = 주유소 들리는 횟수
    priority_queue<int, vector<int>, less<int>> pq;

    sort(gas.begin(), gas.end(), less<pair<int, int>>()); // 주유소 정렬

    gasIdx = 0;
    result = 0;

    while(p < l) {
        for(int i = gasIdx; i < n; i++) {
            if(gas[i].first <= p) {
                pq.push(gas[i].second);
            }
            else {
                gasIdx = i;
                break;
            }
        }

        if(pq.empty()) {
            return -1;
        }

        p += pq.top();
        pq.pop();
        result++;
    }
    
    // 결과 반환
    return result;
}