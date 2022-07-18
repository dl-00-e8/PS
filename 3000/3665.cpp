#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int tc, n, m;
int lastRank[501];
int indigree[501];
void topologySort();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--) {
        memset(lastRank, 0, sizeof(lastRank));
        memset(indigree, 0, sizeof(indigree));

        cin >> n;
        for(int i = 1; i < n + 1; i++) {
            int input;
            cin >> input;
            lastRank[input] = i;
            indigree[input] = i - 1;
        }

        cin >> m;
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if(lastRank[a] < lastRank[b]) {
                indigree[a]++;
                indigree[b]--;
            }
            else {
                indigree[a]--;
                indigree[b]++;
            }
        }

        topologySort();
    }

    return 0;
}

void topologySort() {
    queue<int> q;
    vector<int> result;

    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        if(q.size() != 1) {
            cout << "IMPOSSIBLE" << endl;
            return ;
        }

        int now = q.front();
        q.pop();

        result.push_back(now);

        for(int i = 1; i < n + 1; i++) {
            indigree[i]--;

            if(indigree[i] == 0) {
                q.push(i);
            }
        }

    } 

    if(result.size() == n) {
        for(auto now : result) {
            cout << now << " ";
        }

        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}