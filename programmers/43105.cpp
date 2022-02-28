#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[502][502];
    
    memset(dp, 0, sizeof(dp));
    for(int i = triangle.size() - 1; 0 <= i; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    
    answer = dp[0][0];
    
    return answer;
}