#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k, answer;
int input[10];
bool visited[10];
void backTracking(int now, int depth, int height);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i < n + 1; i++){
        cin >> input[i];
    }

    solve();

    return 0;
}

void backTracking(int now, int depth, int height) {
    if(depth == n) {
        height += input[now];

        if(height >= 500) {
            answer++;
        }
        
        return ;
    }

    if(depth > 1) {
        height -= k;

        if(height < 500) {
            return ;
        }
    }

    visited[now] = true;
    for(int i = 1; i < n + 1; i++) {
        if(!visited[i]) {
            backTracking(i, depth + 1, height + input[i]);
        }
    }
    visited[now] = false;
}

void solve() {
    answer = 0;

    for(int i = 1; i < n + 1; i++) {
        backTracking(i, 1, 500);
    }

    cout << answer << endl;
}