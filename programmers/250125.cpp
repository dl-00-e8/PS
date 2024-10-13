#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int answer = 0;
    
    for(int i = 0; i < 4; i++) {
        int nx = h + dx[i];
        int ny = w + dy[i];
        
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
            continue;
        }
        
        if(board[h][w] == board[nx][ny]) {
            answer++;
        }
    }
    
    return answer;
}