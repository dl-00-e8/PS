#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int dp[info.size() + 1][m]; // B가 M개를 훔쳤을 때의 A의 정보를 저장한다.

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 987654321); // info 배열 초기화
    dp[0][0] = 0;
    for(int i = 1; i < info.size() + 1; i++) {
        int a = info[i - 1][0]; // a가 훔쳤을 때, cost
        int b = info[i - 1][1]; // b가 훔쳤을 때, cost
        
        for(int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a); // a의 최솟값 갱신
            
            if(j + b < m) { // m개의 제한 안에 걸릴 때
                dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
            }
        }
    }
    
    
    int result = 987654321;
    for(int i = 0; i < m; i++) {
        result = min(dp[info.size()][i], result);
    }
    if (result >= n) {
        return -1;
    }
    
    return result;
}