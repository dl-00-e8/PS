#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int preSum[250000];
bool prime[250000];
void setting();
void solve(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(prime, 0, sizeof(prime));
    memset(preSum, 0, sizeof(preSum));

    setting();

    while(true) {
        cin >> n;
        
        // 종료 조건
        if(n == 0) {
            break;
        }

        solve(n);
    }

    return 0;
}

void setting() {

    prime[0] = true;
    prime[1] = true; 
    for(int i = 1; i < sqrt(250000); i++) {
        if(prime[i] == 0) {
            for(int j = i + i; j < 250000; j += i) {
                prime[j] = true;
            }
        }
    }

    preSum[0] = 0;
    for(int i = 1; i < 250000; i++) {
        if(prime[i] == 0) {
            preSum[i] = preSum[i - 1] + 1;
        }
        else {
            preSum[i] = preSum[i - 1];
        }

        // cout << preSum[i] << " ";
        // if(i % 10 == 0) {
        //     cout << endl;
        // }
    }
}

void solve(int n) {
    cout << preSum[2 * n] - preSum[n] << endl;
}