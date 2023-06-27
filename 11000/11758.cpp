#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

vector<pair<int, int> > v;
double calc(int a, int b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < 3; i++) {
        int a, b; 

        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }

    solve();

    return 0;
}

// 나눗셈 정밀 연산 이슈로 미사용
double calc(int a, int b) {
    return (1.0) * (v[b].second - v[a].second) / (v[b].first - v[a].first);
}

void solve() {
    if((v[2].second - v[0].second) * (v[1].first - v[0].first) == (v[1].second - v[0].second) * (v[2].first - v[0].first)) { // 일직선인 경우
        cout << 0 << endl;
        return ;
    }
    else if((v[2].second - v[0].second) * (v[1].first - v[0].first) > (v[1].second - v[0].second) * (v[2].first - v[0].first)) {
        cout << 1 << endl;
        return ;
    }
    else if((v[2].second - v[0].second) * (v[1].first - v[0].first) < (v[1].second - v[0].second) * (v[2].first - v[0].first)){
        cout << -1 << endl;
        return ;
    }
}

/*
y2 - y0 / x2 - x0 = y1 - y0 / x1 - x0
(y2 - y0) * (x1 - x0) = (y1 - y0) * (x2 - x0)
*/