#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int frontIdx = 0;
    
    // 정렬
    sort(people.begin(), people.end(), less<int>());
    
    // 구명보트 풀이
    for(int i = people.size() - 1; i >= 0; i--) {
        if(i == frontIdx) {
            answer++;
        }
        else if(i > frontIdx) {
            if(people[i] + people[frontIdx] <= limit) {
                answer++;
                frontIdx++;
            }
            else {
                answer++;
            }
        }
    }
    
    return answer;
}