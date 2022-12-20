#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<int> input;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        input.push_back(temp);
    }

    solve();

    return 0;
}

void solve() {    
    int result = 0;
    
    sort(input.begin(), input.end());
    

    if(n % 2 == 0) {
        for(int i = n - 1; i > n / 2 - 1; i--) {   
            result += input[i] * 2;
        }    
    }
    else {
        for(int i = n - 1; i > n / 2; i--) {
            result += input[i] * 2;
        }
        result += input[n / 2];
    }
    

    cout << result << endl;
}