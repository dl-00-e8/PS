#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
int arr[1001];
int visited[1001];
void solve(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    fill(&visited[0], &visited[0] + sizeof(visited) / sizeof(int), INF);
    
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }

    solve(1);

    return 0;
}

void solve(int start) {
    queue<int> q;

    q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int now = q.front();

        q.pop();

        for(int i  = now - arr[now]; i <= now + arr[now]; i++) {
            if(i == now) {
                continue;
            }

            // cout << "now : " << now << " i : " << i << endl;

            // range exception
            if(i < 1 || i > n) {
                continue;
            }

            if(visited[now] + 1 < visited[i]) {
                visited[i] = visited[now] + 1;
                q.push(i);
            }
        }
    }
    
    // for(int i = 1; i < n + 1; i++) {
    //     cout << visited[i] << " ";
    // }
    // cout << endl;

    if(visited[n] == INF) {
        cout << - 1 << endl;
    }
    else {
        cout << visited[n] << endl;
    }
}
