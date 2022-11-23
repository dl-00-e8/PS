#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, result;
string input;
bool visited[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    result = 0;
    memset(visited, 0, sizeof(visited));
    
    cin >> n >> m >> input;
    for(int i = 0; i < m; i++) {
        if(visited[i]) {
            continue;
        }
//        cout << i << endl;
        visited[i] = true;

        if(input[i] == 'I') {
            int cnt = 1;
            
            for(int j = i + 1; j < m; j++) {
                if(input[j] != input[j - 1]) {
                    visited[j] = true;
                    if(input[j] == 'I') {
                        cnt++;
                        if(cnt >= n + 1) {
                            result++;
                        }
                    }
                }
                else {
                    break;
                }
            }
        }
        else if(input[i] == 'O') {
            continue;
        }
    }

    cout << result << endl;

    return 0;
}