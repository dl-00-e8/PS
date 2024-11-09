#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

bool asc(vector<int> a, vector<int> b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {    
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    
    sort(jobs.begin(), jobs.end(), asc);
    
    int idx = 0;
    int time =0;
    int answer = 0;
    while(!pq.empty() || idx < jobs.size()) {
        // 현재 시간까지 진입한 작업 정리
        while(idx < jobs.size() && jobs[idx][0] <= time) {
            pq.push({jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        if(pq.empty()) {
            time++;
            continue;
        }
        
        pair<int, int> now = pq.top();
        pq.pop();
        time += now.second;
        answer += (time - now.first);
    }
    
    return answer / jobs.size();
}