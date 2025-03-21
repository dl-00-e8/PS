#include <bits/stdc++.h>

using namespace std;

// 길이가 작은 애 우선순위, 사전순 앞이 우선순위
bool compare(string s1, string s2) {
    if(s1.size() == s2.size()) {
        return s1 < s2;
    }
    
    return s1.size() < s2.size();
}

string get_string(long long n) {
    stack<char> s;
    
    while(n > 0) {
        int remain = n % 26;
        n /= 26;
        
        if(remain == 0) {
            n--;
            s.push('z');
        } else {
            s.push('a' + remain - 1);
        }
    }
    
    // Reverse 진행
    string result = "";
    while(!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    return result;
}

string solution(long long n, vector<string> bans) {
    queue<string> q;
    
    // 정렬 진행
    sort(bans.begin(), bans.end(), compare);
    for(auto ban: bans) {
        q.push(ban);
    }
    
    int length = 0; // n의 글자수 예상
    while(pow(26, length) < n) {
        length++;
        
        // 현재 글자수보다 작은 글자수이면 지워야 한다.
        while(!q.empty()) {
            string now = q.front();
            string target = get_string(n);
            
            if(now.size() < length || (now.size() == length && now <= target)) {
                n++;
                q.pop();
            } else {
                break;
            }
        }
    }
    
    return get_string(n);
}