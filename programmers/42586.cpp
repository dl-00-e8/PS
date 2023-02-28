#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for(int i = 0; i < progresses.size(); i++) {
        int temp = 100 - progresses[i];
        
        if(temp % speeds[i] == 0) {
            days.push_back((temp / speeds[i]));
        }
        else {
            days.push_back((temp / speeds[i]) + 1);
        }
    }
                           
    int idx, max;
    for(int i = 0; i < days.size(); i++) {
        if(answer.empty()) {
            answer.push_back(1);
            max = days[i];
            idx = 0;
        }
        else {
            if(max >= days[i]) {
                answer[idx]++;
            }
            else {
                max = days[i];
                idx++;
                answer.push_back(1);
            }
        }
    }
    
    return answer;
}