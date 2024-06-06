#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int T, N;
vector<int> v;
int gcd(int x, int y);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N;

        for(int i = 0; i < N; i++) {
            int input;

            cin >> input;
            v.push_back(input);
        }

        solve();

        vector<int> temp;
        swap(v, temp);
    }

    return 0;
}

int gcd(int x, int y) {
    if(x % y == 0) {
        return y;
    }
    
    return gcd(y, x % y);
}

void solve() {
    int result;
    vector<int> diff;

    sort(v.begin(), v.end());
    for(int i = 0;  i < v.size() - 1; i++) {
        if(v[i + 1] - v[i] != 0) {
            diff.push_back(v[i + 1] - v[i]);
        }
    }

    // 모두 같은 수일 경우, 무한대로 발산
    if(diff.empty()) {
        cout << "INFINITY" << endl;
        return;
    }
    
    result = diff[0];
    for(int i = 1; i < diff.size(); i++) {
        result = gcd(result, diff[i]);
    }

    cout << result << endl;
}