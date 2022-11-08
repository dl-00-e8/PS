#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    int maxNum = 0;
    int cnt[1000001];
    vector<int> answer;
    vector<pair<int, int>> result;
    
    memset(cnt, 0, sizeof(cnt));
    
    // s 읽어서 숫자만 분리
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{' || s[i] == '}' || s[i] == ' ' || s[i] == ',') {
            continue;
        }
        else if('0' <= s[i] && s[i] <= '9') {
            int now = s[i] - '0';
            
            // 연속된 숫자인지 파악
            for(int j = i + 1; j < s.size(); j++) {
                if('0' <= s[j] && s[j] <= '9') {
                    int temp = s[j] - '0';
                    now = now * 10 + temp;
                }
                else {
                    maxNum = max(maxNum, now);
                    cnt[now]++;
                    i = j;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < maxNum + 1; i++) {
        if(cnt[i]) {
            result.push_back({cnt[i], i});
        }
    }
    
    sort(result.begin(), result.end(), greater<pair<int, int>>());
    
    for(int i = 0 ; i < result.size(); i++) {
        answer.push_back(result[i].second);
    }
    
    return answer;
}