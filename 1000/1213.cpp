#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string input;
map<char, int> m;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    solve();

    return 0;
}

void solve() {
    // 홀수 개수인 알파벳이 하나만 있어야 함.
    int oddCnt = 0;
    char oddKey;
    vector<char> result;

    for(int i = 0; i < input.size(); i++) {
        auto iter = m.find(input[i]);
        if(iter != m.end()) {
            iter->second++;
        }   
        else {
            m.insert({input[i], 1});
        } 
    }

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second % 2 == 1) {
            oddCnt++;
            oddKey = iter->first;
        }
        for(int i = 0; i < iter->second / 2; i++) {
            result.push_back(iter->first);
        }

        if(oddCnt > 1) {
            cout << "I'm Sorry Hansoo" << endl;
            return ;
        }
    }

    // Output
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    if(oddCnt != 0) {
        cout << oddKey;
    }
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}