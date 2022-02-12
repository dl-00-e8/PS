#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, result;
vector<pair<int, int>> lecture;
bool compare(pair<int, int> &a, pair<int, int> &b);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int num, start, end;
        cin >> num >> start >> end;
        lecture.push_back({start, end});
    }

    solve();

    return 0;
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

void solve() {
    result = 0;

    sort(lecture.begin(), lecture.end(), compare);


    for(int i = 0; i < n; i++) {
        if(pq.size() > 0) {
            if(pq.top().first > lecture[i].first) {
                result++;
            }
            else {
                pq.pop();
            }
        }
        else {
            result++;
        }
        pq.push({lecture[i].second, lecture[i].first});
    }

    cout << result << endl;
}