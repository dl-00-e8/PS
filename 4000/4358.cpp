#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int cnt = 0;
string s;
map<string, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(getline(cin, s)) {
        cnt++;
        
        auto iter = m.find(s);
        if(iter != m.end()) {
            iter->second++;
        }
        else {
            m.insert({s, 1});
        }
    }

    
    cout << fixed;
    cout.precision(4);
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        double result = (double)iter->second * 100 / cnt;

        cout << iter->first << " " << result << endl;    
    }

    return 0;
}