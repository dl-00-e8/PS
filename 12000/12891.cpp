#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int s, p;
int preSum[1000001][4];
int minimum[4];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(preSum, 0, sizeof(preSum));

    cin >> s >> p;
    for(int i = 1; i < s + 1; i++) {
        char input;
        cin >> input;

        if(input == 'A') {
            preSum[i][0] = preSum[i - 1][0] + 1;
            preSum[i][1] = preSum[i - 1][1];
            preSum[i][2] = preSum[i - 1][2];
            preSum[i][3] = preSum[i - 1][3];
        }   
        else if(input == 'C') {
            preSum[i][0] = preSum[i - 1][0];
            preSum[i][1] = preSum[i - 1][1] + 1;
            preSum[i][2] = preSum[i - 1][2];
            preSum[i][3] = preSum[i - 1][3];
        } 
        else if(input == 'G') {
            preSum[i][0] = preSum[i - 1][0];
            preSum[i][1] = preSum[i - 1][1];
            preSum[i][2] = preSum[i - 1][2] + 1;
            preSum[i][3] = preSum[i - 1][3];
        }
        else {
            preSum[i][0] = preSum[i - 1][0];
            preSum[i][1] = preSum[i - 1][1];
            preSum[i][2] = preSum[i - 1][2];
            preSum[i][3] = preSum[i - 1][3] + 1;
        }
    }

    for(int i = 0; i < 4; i++) {
        cin >> minimum[i];
    }

    solve();

    return 0;
}

void solve() {
    int cnt = 0;

    for(int i = s; i > p - 1; i--) {
        int tempA, tempC, tempG, tempT;

        tempA = preSum[i][0] - preSum[i - p][0];
        tempC = preSum[i][1] - preSum[i - p][1];
        tempG = preSum[i][2] - preSum[i - p][2];
        tempT = preSum[i][3] - preSum[i - p][3];

        if(tempA >= minimum[0] && tempC >= minimum[1] && tempG >= minimum[2] && tempT >= minimum[3]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}