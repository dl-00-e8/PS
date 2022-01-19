#include <bits/stdc++.h>

using namespace std;

vector<int> j;
vector<int> b;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 2; i++) {
        int input;
        cin >> input;
        j.push_back(input);
    }

    for(int i = 0; i < 2; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }

    solve();

    return 0;
}

void solve() {
    int result;
    
    if(j[0] < b[0]) {
        if(j[1] < b[0]) {
            result = (j[1] - j[0]) + (b[1] - b[0]);
        }
        else if(j[1] >= b[0]) {
            if(j[1] <= b[1]) {
                result = b[1] - j[0];
            }
            else if(j[1] > b[1]) {
                result = j[1] - j[0];
            }
        }
    }
    else if(j[0] > b[0]) {
        if(j[0] > b[1]) {
            result = (j[1] - j[0]) + (b[1] - b[0]);
        }
        else if(j[0] <= b[1]) {
            if(j[1] >= b[1]) {
                result = j[1] - b[0];
            }
            else if(j[1] < b[1]) {
                result = b[1] - b[0];
            }
        }
    }
    else {
        if(j[1] == b[1]) {
            result = j[1] - j[0];
        }
        else if(j[1] > b[1]) {
            result = j[1] - j[0];
        }
        else if(j[1] < b[1]) {
            result = b[1] - b[0];
        }
    }

    cout << result << endl;
}