#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int front, back;
    int answer = 0;
    vector<int> have(n + 1, 1);
    
    sort(lost.begin(), lost.end(), less<int>());
    sort(reserve.begin(), reserve.end(), less<int>());
    
    for(int i = 0; i < lost.size(); i++) {
        have[lost[i]]--;
    }
    
    for(int i = 0; i < reserve.size(); i++) {
        have[reserve[i]]++;
    }
    
    for(int i = 1; i < n + 1; i++) {        
        if(have[i] == 0) {
            front = i - 1;
            back = i + 1;
            if(0 < front && front <= n && have[front] > 1) {
                have[front]--;
                have[i]++;
                continue;
            }
            
            if(0 < back && back <= n && have[back] > 1) {
                have[back]--;
                have[i]++;
                continue;
            }
        }
    }
    
    for(int i = 1; i < n + 1; i++) {
        if(have[i] > 0) {
            answer++;
        }
    }
    
    return answer;
}