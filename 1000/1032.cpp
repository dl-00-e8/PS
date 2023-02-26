#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
string first, input;
bool check[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(check, 1, sizeof(check));

    cin >> n;
    if(n == 1) {
        cin >> input;

        cout << input << endl;
    }
    else {
        cin >> first;

        for(int i = 0; i < n - 1; i++) {
            cin >> input;

            for(int j = 0; j < input.size(); j++) {
                if(first[j] != input[j]) {
                    check[j] = false;
                }
            }
        }

        for(int i = 0; i < first.size(); i++) {
            if(check[i]) {
                cout << first[i];
            }
            else {
                cout << "?";
            }
        }
        cout << endl;
    }

    return 0;
}