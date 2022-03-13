#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll now, p;
vector<ll> v;
set<ll> s;
ll makeNum(ll num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now >> p;
    s.insert(now);
    v.push_back(now);
    while(true) {
        now = makeNum(now);

        if(s.find(now) == s.end()) {
            v.push_back(now);
            s.insert(now);
        }
        else {
            break;
        }
    }

    int result = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != now) {
            result++;
        }
        else {
            break;
        }
    }

    cout << result << endl;

    return 0;
}

ll makeNum(ll num) {
    ll answer = 0;

    while(num) {
        ll temp = num % 10;
        answer += pow(temp, p);

        num -= temp;
        num /= 10;
    }

    return answer;
}