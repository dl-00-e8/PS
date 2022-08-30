#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k, result;
int height[300001];
vector<int> differ;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    result = 0;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
        if(i >= 1) {
            differ.push_back(height[i] - height[i - 1]);
            result += (height[i] - height[i - 1]);
        }
    }

    solve();

    return 0;
}

void solve() {
    sort(differ.begin(), differ.end(), greater<int>());

    for(int i = 0; i < k - 1; i++) {
        result -= differ[i];
    }

    cout << result << endl;
}
