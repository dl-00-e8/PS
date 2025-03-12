#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> tops) {
    int cases[2][2][2] = {
        {{2, 1}, {1, 1}},
        {{3, 1}, {2, 1}}
    }; // idx=0: top여부 / idx=1: 왼쪽 삼각형 사용 여부 / idx=2: 오른쪽 삼각형 사용 여부
    int dp[100001][2]; // 맨 오른쪽 삼각형이 사용되고 있는지 여부에 따라 달라짐
    
    memset(dp, 0, sizeof(dp));
    
    if(tops[0] == 0) {
        dp[0][0] = 2;
        dp[0][1] = 1;
    } else {
        dp[0][0] = 3;
        dp[0][1] = 1;
    }
    for(int i = 1; i < n; i++) {
        int top = tops[i];
        
        dp[i][0] = ((dp[i - 1][0] * cases[top][0][0]) + (dp[i -1][1] * cases[top][1][0])) % 10007;
        dp[i][1] = ((dp[i - 1][0] * cases[top][0][1]) + (dp[i -1][1]  * cases[top][1][1])) % 10007;
        
        // cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
    }
    
    // cout << dp[n - 1][0] << " " << dp[n - 1][1] << "\n"; // 8 , 3이 나와야 함
    
    return (dp[n - 1][0] + dp[n - 1][1]) % 10007;
}