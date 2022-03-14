#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<int> a;
vector<int> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), less<int>());

    int result = 0;
    for(int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    cout << result << endl;

    return 0;
}