#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    // 캐시 
    deque<string> cache;
    
    for(auto city: cities) {
        // 대소문자 변환
        transform(city.begin(), city.end(), city.begin(), ::tolower); 
        
        // cache hit
        auto iter = find(cache.begin(), cache.end(), city);
        if(iter != cache.end()) {
            answer++;
            
            // LRU에서 업데이트
            cache.erase(iter);
            cache.push_back(city);
            
        // cache miss
        } else {
            answer += 5;
            
            if(cacheSize == 0) {
                continue;
            }
            
            // LRU 뽑아서 제거
            if(cache.size() >= cacheSize) {
                cache.pop_front();    
            }
            
            // 현재 값 캐시 적재
            cache.push_back(city);
        }
    }
    
    
    return answer;
}