#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int graph[101][101];
void floydWarshall();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 2;
        graph[b][a] = 1;
    }
    
    floydWarshall();

    return 0;
}

void floydWarshall() {
    for(int k = 1; k < n + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(graph[i][j] != 0) {
                    continue;
                }
                else {
                    if(graph[i][k] == 1 && graph[k][j] == 1) {
                        graph[i][j] = 1;
                        graph[j][i] = 2;
                    }
                    else if(graph[i][k] == 1 && graph[k][j] == 2) {
                        continue;
                    }
                    else if(graph[i][k] == 2 && graph[k][j] == 1) {
                        continue;
                    }
                    else if(graph[i][k] == 2 && graph[k][j] == 2) {
                        graph[i][j] = 2;
                        graph[j][i] = 1;
                    }
                }
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        int result = 0;
        for(int j = 1; j < n + 1; j++) {
            if(i == j) {
                continue;
            }
            
            if(graph[i][j] == 0) {
                result++;
            }
        }

        cout << result << endl;
    }
}