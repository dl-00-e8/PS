#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};
int dp[101][101];
int graph[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    memset(dp, 0, sizeof(dp));
    memset(graph, 0, sizeof(graph));
    
    // 물에 잠긴 지역 표시
    for(int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][1] - 1;
        int y = puddles[i][0] - 1;
        
        graph[x][y] = 1;
    }
    
    // dp 시작
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 1) {
                continue;
            }
            
            for(int k = 0; k < 2; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(0 > nx || nx > n - 1 || 0 > ny || ny > m - 1) {
                    continue;
                }
                
                if(graph[nx][ny] != 1) {
                    dp[nx][ny] += dp[i][j];
                    dp[nx][ny] %= 1000000007;
                }
            }
        }
    }
    
    
    answer = dp[n - 1][m - 1] % 1000000007;
    return answer;
}