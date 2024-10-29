#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    unordered_map<int, int> max_um; // min_q에서 지워졌으므로, max_q에서도 지워져야 하는 데이터 정보
    unordered_map<int, int> min_um; // max_q에서 지워졌으므로, min_q에서도 지워져야 하는 데이터 정보
    priority_queue<int, vector<int>, greater<int>> min_q; // 오름차순이므로, 최솟값 큐
    priority_queue<int, vector<int>, less<int>> max_q; // 내림차순이므로, 최댓값 큐
    
    for(auto operation: operations) {
        switch(operation[0]) {
            case 'I': {
                int num_i = stoi(operation.substr(2));
                max_q.push(num_i);
                min_q.push(num_i);
                break;
            }
            case 'D': {
                int type = stoi(operation.substr(2));
                // 최댓값 삭제
                if(type == 1) {
                    // 비어있다면 무시
                    if(max_q.empty()) {
                        break;
                    }
                    
                    // 기존에 삭제되었던 데이터인지 확인
                    while(!max_q.empty()) {
                        int num = max_q.top();
                        max_q.pop();    
                        
                        if(max_um[num] > 0) {
                            max_um[num]--;
                        } else {
                            min_um[num]++;
                            break;
                        }
                    }
                } 
                // 최솟값 삭제
                else if(type == -1) {
                    // 비어있다면 무시
                    if(min_q.empty()) {
                        break;
                    }
                    
                    // 기존에 삭제되었던 데이터인지 확인
                    while(!min_q.empty()) {
                        int num = min_q.top();
                        min_q.pop();
                        
                        if(min_um[num] > 0) {
                            min_um[num]--;
                        } else {
                            max_um[num]++;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    
    while(!max_q.empty()) {
        int num = max_q.top();
        
        if(max_um[num] > 0) {
            max_um[num]--;
            max_q.pop();
        } else {
            break;
        }
    }
    if(max_q.empty()) {
        answer.push_back(0);
    } else {   
        answer.push_back(max_q.top());
    }
    
    while(!min_q.empty()) {
        int num = min_q.top();
        
        if(min_um[num] > 0) {
            min_um[num]--;
            min_q.pop();
        } else {
            break;
        }
    }
    if(min_q.empty()) {
        answer.push_back(0);
    } else {
        answer.push_back(min_q.top());
    }
    
    return answer;
}