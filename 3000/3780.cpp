#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n;
int dist[20001];
int parent[20001];
int findParent(int parent[], int x);
void iij(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, 0, sizeof(parent));

    cin >> t;
    while(t--) {
        cin >> n;

        memset(dist, 0, sizeof(dist));
        
        for(int i = 1; i < n + 1; i++) {
            parent[i] = i;
        }

        while(true) {
            char input;
            cin >> input;

            if(input == 'O') {
                break;
            }

            if(input == 'E') {
                int i;
                cin >> i;
                findParent(parent, i);

                cout << dist[i] << endl;
            }
            else if(input == 'I') {
                int i, j;
                cin >> i >> j;
                iij(i, j);
            }
        }
    }

    return 0;
}

int findParent(int parent[], int x) {
    if(parent[x] != x) {
        int px = findParent(parent, parent[x]);
        dist[x] += dist[parent[x]];
        parent[x] = px;
        return parent[x];
    }

    return parent[x];
}

void iij(int a, int b) {
    parent[a] = b;
    dist[a] = abs(a - b) % 1000;
}