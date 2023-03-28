#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<pair<int, int>> v;
    
    // 오름차순 정렬
    sort(tangerine.begin(), tangerine.end(), less<int>());
    
    for(int i = 0; i < tangerine.size(); i++) {
        int now = tangerine[i];
        
        int cnt = 0;
        while(tangerine[i] == now) {
            cnt++;
            i++;
        }
        i--;
        
        v.push_back({cnt, now});
    }
    
    // cnt 높은 순으로 정렬
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    
    int temp = 0;
    for(int i = 0; i < v.size(); i++) {
        temp += v[i].first;
        answer++;
        
        if(temp >= k) {
            break;
        }
    }
    
    return answer;
}