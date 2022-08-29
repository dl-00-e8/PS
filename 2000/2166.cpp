#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
double result;
vector<pair<int, int>> pos;
double ccw(double x1, double y1, double x2, double y2, double x3 , double y3);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        pos.push_back({x, y});
    }

    result = 0;
    for(int i = 1; i < n; i++) {
        result += ccw(pos[0].first, pos[0].second, pos[i - 1].first, pos[i - 1].second, pos[i].first, pos[i].second);
    }
    
    cout << fixed;
    cout.precision(1);
    cout << abs(result) << endl;

    return 0;
}

double ccw(double x1, double y1, double x2, double y2, double x3 , double y3) {
    double temp = (x1 * y2) + (x2 * y3) + (x3 * y1);
    temp += (-(y1 * x2) - (y2 * x3) - (y3 * x1));

    return temp / 2;
}