#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, c, m;
vector<pair<pair<int, int>, int>> box;
int truck[2001];
bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b); //first.first : start, first.second : dest, second : count
void solve();

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(truck, 0, sizeof(truck));

    cin >> n >> c >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        box.push_back({{a, b}, c});
    }

    solve();

    return 0;
}

bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    if(a.first.second == b.first.second) {
        return a.first.first < b.first.first;
    }

    return a.first.second < b.first.second;
}

void solve() {
    int result = 0;

    sort(box.begin(), box.end(), compare);

    for(auto now : box) {
        int maxBox = 0;
        int start = now.first.first;
        int dest = now.first.second;
        int capacity = now.second;

        for(int i = start; i < dest; i++) {
            maxBox = max(maxBox, truck[i]);
        }

        maxBox = min(c - maxBox, capacity);
        result += maxBox;

        for(int i = start; i < dest; i++) {
            truck[i] += maxBox;
        }
    }

    cout << result << endl;
}