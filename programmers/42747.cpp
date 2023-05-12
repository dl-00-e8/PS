#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = citations[0]; i > -1; i--) {
        int cnt = 0;
        
        for(auto c : citations) {
            if(c >= i) {
                cnt++;
            }
        }
        
        if(cnt >= i) {
            return i;
        }
    }    
    return answer;
}