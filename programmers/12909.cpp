#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stack;

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        
        if(stack.empty()) {
            if(c == '(') {
                stack.push(c);
            }
            else if(c == ')') {
                answer = false;
                break;
            }
        }
        else {
            if(c == ')') {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
    }
    
    if(!stack.empty()) {
        answer = false;
    }
    
    return answer;
}