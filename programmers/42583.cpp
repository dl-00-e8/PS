#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int now = 0; // 현재 다리 위의 트럭의 총 무게
    queue<int> q; // 현재 다리 위에 있는 트럭 확인
    
    for(int idx = 0; idx < truck_weights.size(); idx++) { 
        int truck = truck_weights[idx];
        
        while(true) {
            // 다리 위에 아무도 없을 경우
            if(q.empty()) {
                now += truck;
                q.push(truck);
                answer++;
                break;
            // 다리에 트럭 꽉 차있으면, 트럭 한명 방출
            } else if(q.size() == bridge_length) {
                int value = q.front();
                q.pop();
                now -= value;
            // 트럭 다리 건너려는 시도 진행
            } else {
                // 무게 여유 있다면
                if(now + truck <= weight) {
                    q.push(truck);
                    now += truck;
                    answer++;
                    break;
                // 무게 여유 없으면, 트럭 한 명 다리 건넘
                } else {
                    q.push(0);
                    answer++;
                }
            }
        }
    }
    
    // 아직 다리 위에 트럭이 남아있다면
    if(!q.empty()) {
        answer += bridge_length;
    }
    
    return answer;
}