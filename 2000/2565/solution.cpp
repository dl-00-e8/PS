#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX_INT 987654321

int N;
vector<pair<int, int> > line;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}
int binary_search(int start, int end, int val, int lis[]);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }

    // 정렬
    sort(line.begin(), line.end(), compare);

    int lis[N];

    fill(&lis[0], &lis[0] + sizeof(lis) / sizeof(int), MAX_INT);

    int lis_last_idx = 0;
    lis[0] = line[0].second;
    for(int i = 1; i < line.size(); i++) {
        int val = line[i].second;
        if(lis[lis_last_idx] <= val) {
            lis[++lis_last_idx] = val;
        } else {
            int idx = binary_search(0, lis_last_idx, val, lis);
            lis[idx] = val;
        }
    }

    cout << N - (lis_last_idx + 1) << endl;

    return 0;
}

int binary_search(int start, int end, int val, int lis[]) {
    while(start < end) {
        int mid = (start + end) / 2;

        if(val > lis[mid]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return end;
}