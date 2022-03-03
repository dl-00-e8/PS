#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int num[9];
bool visited[9];
void choose(int idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    choose(0);

    return 0;
}

void choose(int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i++) {
            cout << num[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            num[idx] = i;
            visited[i] = true;
            choose(idx + 1);
            visited[i] = false;
        }
    }
}