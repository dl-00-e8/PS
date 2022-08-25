#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n;
ll arr[100001];
void solve(); 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    
    solve();

    return 0;
}

void solve() {
    ll left, right, result, resultLeft, resultRight, median;

    left = 0;
    right = n - 1;

    result = abs(arr[left] + arr[right]);
    resultLeft = arr[left];
    resultRight = arr[right];

    while(left < right) {
        median = arr[left] + arr[right];

        if(abs(median) < result) {
            result = abs(median);
            resultLeft = arr[left];
            resultRight = arr[right];
        }

        if(median < 0) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << resultLeft << " " << resultRight << endl;
}