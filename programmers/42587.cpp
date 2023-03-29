#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int importance[10];
    vector<int> result;
    queue<int> q;
    
    // setting 0
    memset(importance, 0, sizeof(importance));
    
    for(int i = 0; i < priorities.size(); i++) {
        importance[priorities[i]]++;
        q.push(i);
    }
    
    int maxImp = *max_element(priorities.begin(), priorities.end());
    
    while(!q.empty()) {
        int now = q.front();
    
        q.pop();
        
        if(priorities[now] < maxImp) {
            q.push(now);
        }
        else {
            result.push_back(now);
            
            importance[priorities[now]]--;
            if(importance[priorities[now]] == 0) {
                maxImp--;
                while(importance[maxImp] == 0) {
                    maxImp--;
                }
            }
        }
    }
    
    for(int i = 0; i < result.size(); i++) {
        if(result[i] == location) {
            answer = i + 1;
        }
    }
    
    
    return answer;
}