#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>, less<int>> pq; // 내림차순 우선순위 큐
    
    for(auto work: works) {
        pq.push(work);
    }
    
    while(n--) {
        int now = pq.top();
        pq.pop();
        
        if(now >= 1) {
            now--;    
        }
        pq.push(now);
    }
    
    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();
        
        answer += now * now;
    }
    
    return answer;
}