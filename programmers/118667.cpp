#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, max_num = 0; // 전체 수의 합: total, 가장 큰 수: max_num
    ll sum_1 = 0, sum_2 = 0, total = 0;
    int limit_cnt = queue1.size() * 4;
    queue<int> q1, q2;
    
    for(auto value: queue1) {
        total += value;
        max_num = max(max_num, value);
        sum_1 += value;
        q1.push(value);
    }
    for(auto value: queue2) {
        total += value;
        max_num = max(max_num, value);
        sum_2 += value;
        q2.push(value);
    }
    
    // 총합이 홀 수이거나, 특정 원소가 절반보다 큰 경우
    if(total % 2 != 0 || total / 2 < max_num) {
        return -1;
    }
    
    while(sum_1 != sum_2) {
        if(sum_1 > sum_2) {
            int now = q1.front();
            q1.pop();
            q2.push(now);
            sum_1 -= now;
            sum_2 += now;
            answer++;
        } else {
            int now = q2.front();
            q2.pop();
            q1.push(now);
            sum_2 -= now;
            sum_1 += now;
            answer++;
        }
        
        if(answer > limit_cnt) {
            return -1;
        }
    }
    
    return answer;
}