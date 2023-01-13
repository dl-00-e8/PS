#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int m, n;
vector<int> planet[11];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for(int i = 1; i < m + 1; i++) {
        for(int j = 0; j < n; j++) {
            int input;
            cin >> input;
            planet[i].push_back(input);
        }
    }

    solve();

    return 0;
}

void solve() {
    int result = 0;
    
    for(int i = 1; i < m + 1; i++) {
        for(int j = i + 1; j < m + 1; j++) {
            int add = true;

            for(int a = 0; a < n; a++) {
                for(int b = a + 1; b < n; b++) {
                    if(planet[i][a] < planet[i][b] && planet[j][a] < planet[j][b]) {
                        continue;
                    }
                    else if(planet[i][a] == planet[i][b] && planet[j][a] == planet[j][b]) {
                        continue;
                    }
                    else if(planet[i][a] > planet[i][b] && planet[j][a] > planet[j][b]) {
                        continue;
                    }
                    else {
                        add = false;
                    }
                }
            }

            if(add) {
                result++;
            }
        }
    }

    cout << result << endl;
}