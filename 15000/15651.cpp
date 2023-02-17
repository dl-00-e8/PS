#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
vector<int> answer;
void backTracking(int len);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    backTracking(0);

    return 0;
}

void backTracking(int len) {
    if(len == m) {
        for(int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;

        return;
    }

    for(int i = 1; i < n + 1; i++) {
        answer.push_back(i);
        backTracking(len + 1);
        answer.pop_back();
    }
}