#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n, m, result;
queue<pair<int, int>> q;
int cnt[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        while(!q.empty()) {
            q.pop();
        }

        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            int input;
            cin >> input;

            q.push({input, i});
            cnt[input]++;
        }

        result = 0;
        while(!q.empty()) {
            int nowIdx = q.front().second;
            int importance = q.front().first;

            q.pop();

            bool check = false;
            for(int i = importance + 1; i < 10; i++) {
                if(cnt[i] > 0) {
                    check = true;
                }
            }

            if(check) {
                q.push({importance, nowIdx});
            }
            else {
                result++;
                cnt[importance]--;

                if(nowIdx == m) {
                    cout << result << endl;
                    break;
                }
            }
        }
    }

    return 0;
}