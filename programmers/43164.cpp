#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> result;

void back_tracking(int depth, string start, vector<string> route, bool visited[], vector<vector<string>> tickets) {
    if(depth == tickets.size()) {
        result.push_back(route);
        return ;
    }
    
    for(int idx = 0; idx < tickets.size(); idx++) {
        string t_start = tickets[idx][0];
        string t_dest = tickets[idx][1];
        
        if(start == t_start && !visited[idx]) {
            visited[idx] = true;
            route.push_back(t_dest);
            back_tracking(depth + 1, t_dest, route, visited, tickets);
            route.pop_back();
            visited[idx] = false;
        }   
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> route;
    bool visited[tickets.size()];
    
    memset(visited, 0, sizeof(visited));
    
    route.push_back("ICN");
    back_tracking(0, "ICN", route, visited, tickets);
    
    // 정렬 후, 오름차순의 결과 반환
    sort(result.begin(), result.end());
    return result[0];
}

/**
 * 첫 번째 접근 방식: 사전순으로 오름차순 정렬을 원한다는 점에서, DFS에서 다음 목적지를 사전 순으로 정렬했었음
 * 위 방식은, 모든 비행기 티켓을 사용해야 한다는 점과 위반되는 요소가 발생
 * 만약 A->C, C->A, A->B라는 티켓이 존재할 때 사전 순으로 정렬한다면, A->B로 간 이후에 모든 비행기 티켓을 사용하지 못하고 종료해버리는 코드가 된다.
 * 
 * 위 방식의 문제점을 해결하기 위해, 백트래킹으로 완전탐색을 진행했다.
 * 완전탐색을 통해, 가능한 모든 경우의 수를 구한 이후 정렬을 통해 해결했다.
 */