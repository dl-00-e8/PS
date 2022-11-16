#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321
#define ll long long

int n, m;
int dist[201][201];
void floydWarshall();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    floydWarshall();

    return 0;
}

void floydWarshall() {
    ll result = INF;
    int answer = n + 1;

    for(int k = 1; k < n + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        ll temp = 0;

        for(int j = 1; j < n + 1; j++) {
            if(i != j) {
                temp += dist[i][j];
            }
        }

        if(result > temp) {
            answer = i;
            result = temp;
        }
        else if(result == temp) {
            answer = min(answer, i);
        }
    }

    cout << answer << endl;
}