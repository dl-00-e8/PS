#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, now;
vector<int> input;
vector<int> result;
int gcd(int a, int b);

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

    // 오름차순 정렬
    sort(input.begin(), input.end(), less<int>());

    now = input[1] - input[0];
    for(int i = 2; i < n; i++) {
        now = gcd(now, input[i] - input[i - 1]);
    }

    for(int i = 2; i <= sqrt(now); i++) {
        if(now % i == 0) {
            result.push_back(i);
            result.push_back(now / i);
        }
    }
    result.push_back(now);

    // Output
    sort(result.begin(), result.end(), less<int>());
    result.erase(unique(result.begin(), result.end()), result.end());
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}