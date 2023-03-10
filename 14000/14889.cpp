#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, result;
int graph[21][21];
bool visited[21];
void combination(int now, int cnt, int depth);
void calc();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            cin >> graph[i][j];
        }
    }

    result = 987654321;

    solve();

    cout << result << endl;

    return 0;
}

void combination(int now, int cnt, int depth) {
    // 조합 완료되면 계산 진행    
    if(cnt == depth) {
        calc();
    }

    // 조합만들기
    for(int i = now; i < n + 1; i++) {
        visited[i] = true;
        combination(i + 1, cnt + 1, depth);
        visited[i] = false;
    }
}

void calc() {
    int aC = 0, bC = 0;
    vector<int> a;
    vector<int> b;

    for(int i = 1; i < n + 1; i++) {
        if(visited[i]) {
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            aC += graph[a[i]][a[j]];
        }
    }

    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            bC += graph[b[i]][b[j]];
        }
    }
    
    result = min(result, abs(aC - bC));
}

void solve() {
    for(int i = 1; i < n + 1; i++) {
        memset(visited, 0, sizeof(visited));
        
        combination(i, 0, n / 2);
    }
}