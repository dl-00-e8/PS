#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
int arr[500001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(arr, 0, sizeof(arr));

    cin >> N;
    for(int i = 1; i < N + 1; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}

void solve() {
    stack<int> s;

    for(int i = 1; i < N + 1; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            s.pop();
        }

        if(!s.empty()) {
            cout << s.top() << endl;
        }
        else {
            cout << 0 << endl;
        }

        s.push(i);
    }
}