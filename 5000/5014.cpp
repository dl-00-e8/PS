#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int f, s, g, u, d;
int building[1000001];
void dfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    dfs();

    return 0;
}

void dfs() {
    fill(&building[0], &building[0] + sizeof(building) / sizeof(int), INF);

    queue<int> q;

    q.push(s);
    building[s] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        int upNow = now + u;
        int downNow = now - d;

        if(1 <= upNow && upNow <= f) {
            if(building[upNow] > building[now] + 1) {
                building[upNow] = building[now] + 1;
                q.push(upNow);
            }
        }

        if(downNow >= 1 && downNow <= f) {
            if(building[downNow] > building[now] + 1) {
                building[downNow] = building[now] + 1;
                q.push(downNow);
            }
        }
    }

    if(building[g] == INF) {
        cout << "use the stairs" << endl;
    }
    else {
        cout << building[g] << endl;
    }
}