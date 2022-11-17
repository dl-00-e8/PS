#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n;
vector<int> height;
void greedy();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        height.clear();

        cin >> n;

        for(int i = 1; i < n + 1; i++) {
            int input;
            cin >> input;
            height.push_back(input);
        }

        greedy();
    }

    return 0;
}

void greedy() {
    int result = 0;
    
    sort(height.begin(), height.end(), less<int>());

    for(int i = 0; i < n - 2; i++) {
        result = max(height[i + 2] - height[i], result);
    }

    cout << result << endl;
}