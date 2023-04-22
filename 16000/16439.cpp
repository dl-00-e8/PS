#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int arr[31][31];
bool chicken[31];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> arr[i][j];
        }   
    }

    solve();

    return 0;
}

int calc() {
    int result = 0;

    for(int i = 1; i < n + 1; i++) {
        int temp = 0;
        
        for(int j = 1; j < m + 1; j++) {
            if(chicken[j]) {
                temp = max(temp, arr[i][j]);
            }
        }

        result += temp;
    }

    return result;
}

void solve() {
    int answer = 0;
    
    memset(chicken, 0, sizeof(chicken));    

    for(int i = 1; i < m + 1; i++) {
        // 한 마리만 살 경우
        chicken[i] = true;
        answer = max(answer, calc());
        for(int j = i + 1; j < m + 1; j++) {
            // 두 마리만 살 경우
            chicken[j] = true;
            answer = max(answer, calc());
            for(int k = j + 1; k < m + 1; k++) {
                // 세 마리만 살 경우
                chicken[k] = true;
                answer = max(answer, calc());
                chicken[k] = false;
            }
            chicken[j] = false;
        }
        chicken[i] = false;
    }

    cout << answer << endl;
}