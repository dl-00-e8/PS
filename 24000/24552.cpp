#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string input;
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
    int leftCnt, rightCnt, sum;

    leftCnt = 0;
    rightCnt = 0;
    sum = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '(') {
            leftCnt++;
            sum++;
        }
        else if(input[i] == ')') {
            rightCnt++;
            sum--;
        }

        if(sum < 0) {
            cout << rightCnt << endl;
            return ;
        }

        if(sum == 0) {
            leftCnt = 0;
        }
    }

    cout << leftCnt << endl;

}
