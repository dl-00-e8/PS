#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k, s;
int graph[401][401];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = -1;
        graph[b][a] = 1;
    }

    solve();

    cin >> s;
    for(int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;
        cout << graph[a][b] << endl;
    }

    /*
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }   
    */

    return 0;
}

void solve() {
    for(int k = 1; k < n + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {                
                if(i == j || graph[i][k] == 0 || graph[k][j] == 0) {
                    continue;
                }

                if(graph[i][k] == 1) {
                    if(graph[k][j] == 1) {
                        graph[i][j] = 1;
                    }
                }
                else if(graph[i][k] == -1) {
                    if(graph[k][j] == -1) {
                        graph[i][j] = -1;
                    }
                }
            }
        }   
    }
}