#include <bits/stdc++.h>

using namespace std;

int dfs(int width, int height, int idx, vector<vector<int>> sizes) {
    if(idx == sizes.size()) {
        return width * height;
    }
    
    int result = 1000001;
    // 기존
    int n_width = max(width, sizes[idx][0]);
    int n_height = max(height, sizes[idx][1]);
    result = min(result, dfs(n_width, n_height, idx+1, sizes));
    
    // 회전
    n_width = max(width, sizes[idx][1]);
    n_height = max(height, sizes[idx][0]);
    result = min(result, dfs(n_width, n_height, idx+1, sizes));    

    return result;
}

int solution(vector<vector<int>> sizes) {
    int width = 0;
    int height = 0;
    
    for(auto size: sizes) {
        int n_width = max(size[0], size[1]);
        int n_height = min(size[0], size[1]);
        width = max(width, n_width);
        height = max(height, n_height);
    }
    
    return width * height;
}