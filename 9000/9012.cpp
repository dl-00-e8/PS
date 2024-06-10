#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int T;
string solve(string x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        string input;

        cin >> input;

        cout << solve(input) << endl;
    }

    return 0;
}

string solve(string x) {
    stack<char> s;

    for(int i = 0; i < x.length(); i++) {
        char temp = x[i];

        if(temp == '(') {
            s.push(temp);
        }
        else if(temp == ')') {
            if(s.empty()) {
                return "NO";
            }

            if(s.top() == '(') {
                s.pop();
            }
        }
    }

    if(!s.empty()) {
        return "NO";
    }

    return "YES";
}