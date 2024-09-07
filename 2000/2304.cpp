#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
vector<pair<int, int> > v;
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;
        v.push_back(make_pair(L, H));
    }
    
    solve();

    return 0;
}

void solve() {
    // 결과값 초기화
    int result = 0;

    // Vector 정렬
    sort(v.begin(), v.end(), compare);
    
    // 가장 높은 높이 찾기
    int max_height = 0;
    int max_height_idx = 0;
    for(int i = 0; i < N; i++) {
        if(max_height < v[i].second) {
            max_height = v[i].second;
            max_height_idx = i;
        }
    }

    // 왼쪽에서 가장 높은 높이까지의 넓이
    stack<pair<int, int> > left;
    for(int i = 0; i < max_height_idx; i++) {
        if(left.empty()) {
            left.push(v[i]);
        } else {
            if(left.top().second < v[i].second) {
                left.push(v[i]);
            }
        }
    }

    int previous_idx = v[max_height_idx].first;
    int previous_height = max_height;
    while(!left.empty()) {
        int current_idx = left.top().first;
        int current_height = left.top().second;

        result += (previous_idx - current_idx) * current_height;

        previous_idx = current_idx;
        previous_height = current_height;
        left.pop();
    }

    // 오른쪽에서 가장 높은 높이까지의 넓이
    stack<pair<int, int> > right;
    for(int i = N-1; i > max_height_idx; i--) {
        if(right.empty()) {
            right.push(v[i]);
        } else {
            if(right.top().second < v[i].second) {
                right.push(v[i]);
            }
        }
    }

    previous_idx = v[max_height_idx].first + 1;
    previous_height = max_height;
    while(!right.empty()) {
        int current_idx = right.top().first + 1;
        int current_height = right.top().second;

        result += (current_idx - previous_idx) * current_height;

        previous_idx = current_idx;
        previous_height = current_height;
        right.pop();
    }

    result += max_height;

    cout << result << endl;
}