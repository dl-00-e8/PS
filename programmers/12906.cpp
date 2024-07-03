#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    
    for(auto value: arr) {
        if(!s.empty()) {
            if(s.top() == value) {
                continue;
            }
            else {
                s.push(value);
            }
        } else {
            s.push(value);
        }
    }
    
    while(!s.empty()) {
        int now = s.top();
        s.pop();
        
        answer.push_back(now);
    }
    reverse(answer.begin(), answer.end());

    return answer;
}