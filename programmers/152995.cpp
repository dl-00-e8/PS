#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> &v1, vector<int> &v2) {
    if(v1[0] == v2[0]) {
        return v1[1] < v2[1];
    }
    return v1[0] > v2[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<int> wanho = scores[0];
    
    sort(scores.begin(), scores.end(), compare);
    
    int max_cnt = 0;
    for(auto score: scores) {
        if(wanho[0] < score[0] && wanho[1] < score[1]) {
            return -1;
        }
        
        if(score[1] >= max_cnt) {
            max_cnt = score[1];
            
            if(score[0] + score[1] > wanho[0] + wanho[1]) {
                answer++;
            }
            
        }
    }
    
    return answer;
}