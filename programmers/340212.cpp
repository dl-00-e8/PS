#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long answer = limit;
    long long start = 1;
    long long end = limit;
    
    
    while(start <= end) {
        long long result = 0;
        long long level = (start + end) / 2;
        
        for(int i = 0; i < diffs.size(); i++) {
            int time_cur = times[i], time_prev = 0;
            if(i > 0) {
                time_prev = times[i - 1];
            }

            if(diffs[i] <= level) {
                result += time_cur;
            } else {
                result += (time_cur + time_prev) * (diffs[i] - level) + time_cur;
            }
        }
        
        if(result <= limit) {
            answer = min(answer, level);
            end = level - 1;
        } else {
            start = level + 1;
        }
    }
    return answer;
}