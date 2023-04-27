#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        int input;

        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), greater<int>());

    int answer = 0;
    for(int i = 0; i < n; i += 3) {
        if(n - i <= 2) {
            while(i < n) {
                answer += v[i];
                i++;
            }
        }
        else {
            answer += v[i];
            answer += v[i + 1];
        }
    }

    cout << answer << endl;    

    return 0;
}