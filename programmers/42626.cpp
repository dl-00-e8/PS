#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto value: scoville) {
        pq.push(value);
    }
    
    // 2개 이상의 원소가 있으며, 하나라도 K보다 작은 경우에만 무한 반복
    while(pq.size() > 1 && pq.top() < K) {
        int now = pq.top();
        pq.pop();
        
        int next = pq.top();
        pq.pop();
        
        int temp = now + (next * 2);
        
        pq.push(temp);
        
        answer++;
    }
    
    // 아직 작은게 남아있다면
    if(pq.top() < K) {
        return -1;
    }
    
    return answer;
    
}