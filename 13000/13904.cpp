#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, d, w;
vector<pair<int, int>> hw;
bool compare(const pair<int, int> &a, const pair<int, int> &b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> d >> w;
        hw.push_back({d, w});
    }

    solve();
    
    return 0;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }

    return a.first > b.first;
}

void solve() {
    int result, maxIdx, vIdx;
    priority_queue<int, vector<int>, less<int>> pq;

    sort(hw.begin(), hw.end(), compare);

    vIdx = 0;
    result = 0;
    maxIdx = hw[0].first;
    for(int i = maxIdx; i > 0; i--) {
        for(; vIdx < hw.size(); vIdx++) {
            // cout << hw[vIdx].first << " " << hw[vIdx].second << endl;
            if(hw[vIdx].first >= i) {
                pq.push(hw[vIdx].second);
            }
            else {
                break;
            }
        }

        if(!pq.empty()) {
            // cout << pq.top() << endl;
            result += pq.top();
            pq.pop();
        }
    }

    

    cout << result << endl;
}

/*
for(int i = 0; i < hw.size(); i++) {
        if(hw[i].first >= maxIdx) {
            pq.push({hw[i].second, hw[i].first});
        }
        else {
            if(pq.top().second < maxIdx || pq.empty()) {
                maxIdx--;
            }
            else {
                result += pq.top().first;
                pq.pop();
                maxIdx--;
            }

            pq.push({hw[i].second, hw[i].first});
        }
    }

    if(maxIdx > 0) {
        while(maxIdx--) {
            if(!pq.empty()) {
                result += pq.top().first;
            }
        }
    }
*/