#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> data;
    
    for(int i = 0; i < prices.size(); i++) {
        while(!data.empty()) {
            pair<int, int> now = data.top();
            
            if(now.second > prices[i] ) {
                data.pop();
                answer[now.first] = i - now.first;
            } else {
                break;
            }
        }
        
        data.push({i, prices[i]});
    }
    
    while(!data.empty()) {
        pair<int, int> now = data.top();
        data.pop();
        
        answer[now.first] = prices.size() - (now.first + 1);
    }
    return answer;
}