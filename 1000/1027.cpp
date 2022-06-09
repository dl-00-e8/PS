#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int high[51];
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> high[i];
    }

    if(n == 1) {
        cout << 0 << endl;
    }
    else if(n == 2) {
        cout << 1 << endl;
    }
    else {
        cout << solve() << endl;
    }

    return 0;
}

int solve() {
    int result = 0;

    for(int now = 0; now < n; now++) {
        int temp = 0;
        for(int i = 0; i < n; i++) {
            if(i == now) {
                continue;
            }

            // 기울기 확인
            double slope = double(abs(high[now] - high[i])) / abs((now - i));
            
            if(high[now] > high[i]) {
                slope = (-1) * slope;
            }

            if(i < now) {
                bool check = true;
                for(int j = now - 1; j > i; j--) {
                    if(high[now] + (slope * abs(now - j)) <= high[j]) {
                        check = false;
                        break;
                    } 
                }

                if(check) {                    
                    temp++;
                }
            }
            else {
                bool check = true;
                for(int j = now + 1; j < i; j++) {
                    if(high[now] + (slope * abs(now - j)) <= high[j]) {
                        check = false;
                        break;
                    } 
                }    

                if(check) {
                    temp++;
                }
            }
        }
        result = max(temp, result);
    }

    return result;
}