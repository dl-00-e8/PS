#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
vector<int> student;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        int input;
        cin >> input;
        student.push_back(input);
    }

    solve();

    return 0;
}

void solve() {
    int idx = 0;
    int result = 0;
    
    sort(student.begin(), student.end(), less<int>());

    // for(int i = 0; i < n; i++) {
    //     cout << student[i] << " ";
    // }
    // cout << endl;

    for(int i = n - 1; i >= 0; i--) {
        for(; idx < i; idx++) {
            int temp = student[idx] + student[i];

            // cout << i << " " << idx << " " << temp << endl;

            if(temp >= m) {
                result++;
                idx++;
                break;
            }
            else {
                continue;
            }
        }

        if(i <= idx) {
            break;
        }
    }

    cout << result << endl;
}