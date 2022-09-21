#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int arr[1000001];
int nge[1000001];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    fill(nge, nge + sizeof(nge) / sizeof(int), -1);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}

void solve() {
    stack<int> s;

    nge[n] = -1;
    s.push(arr[n]);
    for(int i = n - 1; i > 0; i--) {
        while(!s.empty()) {
            if(s.top() > arr[i]) {
                nge[i] = s.top();
                
                break;
            }

            s.pop();
        }

        s.push(arr[i]);
    }

    for(int i = 1; i < n + 1; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;
}