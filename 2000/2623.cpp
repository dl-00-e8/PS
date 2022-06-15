#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int indigree[1001]; // 진입차수
vector<int> graph[1001];
void topologySort();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(indigree, 0, sizeof(indigree));

    cin >> n >> m;
    for(int i = 1; i < m + 1; i++) {
        int cnt;
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int before, input;
            
            cin >> input;
            
            if(j == 0) {                
                before = input;
                continue;
            }
            else {
                graph[before].push_back(input);
                indigree[input]++;

                before = input;
            }
        }
    }

    topologySort();

    return 0;
}

void topologySort() {
    queue<int> q;
    vector<int> result;

    // 진입차수가 0인 것들 담아주기
    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    // 위상정렬 진행
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(auto visit : graph[now]) {
            indigree[visit]--;

            if(indigree[visit] == 0) {
                q.push(visit);
                result.push_back(visit);
            }
        }
    }

    // 결과 출력
    if(result.size() < n) {
        cout << 0 << endl;
    }
    else if(result.size() == n) {
        for(auto now : result) {
            cout << now << endl;
        }
    }
}