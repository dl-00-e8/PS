#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
int graph[51][51];
int WB[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};
int BW[8][8] = {
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}
};
int check_b(int x, int y);
int check_w(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < M; j++) {
            if(input[j] == 'W') {
                graph[i][j] = 0;
            } else {
                graph[i][j] = 1;
            }
        }
    }

    // backtracking
    int answer = 987654321;
    for(int i = 0; i < N - 7; i++) {
        for(int j = 0; j < M - 7; j++) {
            // cout << i <<  " " << j << " " << check_b(i, j) << " " << check_w(i, j) << endl;
            int temp = min(check_b(i, j), check_w(i, j));
            answer = min(temp, answer);
        }
    }
    
    cout << answer << endl;

    return 0;
}

int check_b(int x, int y) {
    int result = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            // cout << graph[x + i][y + j] << " " << BW[i][j] << endl;
            if(graph[x + i][y + j] != BW[i][j]) {
                result++;
            }
        }
    }

    return result;
}

int check_w(int x, int y) {
    int result = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            // cout << graph[x + i][y + j] << " " << WB[i][j] << endl;
            if(graph[x + i][y + j] != WB[i][j]) {
                result++;
            }
        }
    }

    return result;
}