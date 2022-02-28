#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int now = 0;
    int answer = 0;
    char calc[] = {'+', '-'};
    queue<int> q;
    
    q.push(0);
    for(int i = 0; i < numbers.size(); i++) {
        int size = q.size();
        while(size--) {
            now = q.front();
            q.pop();
            
            for(int j = 0; j < 2; j++) {
                if(calc[j] == '+') {
                    q.push(now + numbers[i]);
                }
                else if(calc[j] == '-') {
                    q.push(now - numbers[i]);
                }
            }
        }
    }
    
    while(!q.empty()) {
        if(q.front() == target) {
            answer++;
        }
        q.pop();
    }
    
    return answer;
}

