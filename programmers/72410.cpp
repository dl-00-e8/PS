#include <bits/stdc++.h>

using namespace std;

char to_lower(char c) {
    if('A' <= c && c <= 'Z') {
        return c + 32;
    }
    
    return c;
}

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for(auto c: new_id) {
        answer += to_lower(c);
    }
    
    // 2단계
    regex pattern2("[^A-Za-z0-9._-]");
    answer = regex_replace(answer, pattern2, "");
    
    // 3단계
    regex pattern3("\\.+");
    answer = regex_replace(answer, pattern3, ".");
    
    // 4단계
    if(answer[0] == '.') {
        answer.erase(answer.begin());
    }
    if(answer[answer.size() - 1] == '.') {
        answer.pop_back();
    }
    
    // 5단계
    if(answer.size() == 0) {
        answer = 'a';
    }
    
    // 6단계
    if(answer.size() >= 16) {
        answer = answer.substr(0, 15);
        if(answer[answer.size() - 1] =='.') {
            answer.pop_back();
        }
    }
    
    // 7단계
    if(answer.size() <= 2) {
        char c = answer[answer.size() - 1];
        while(answer.size() < 3) {
            answer += c;
        }
    }
    
    return answer;
}