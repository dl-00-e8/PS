#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    pair<set<int>, set<int>> players[n + 1]; // Player의 경기 결과를 담고 있는 배열, first는 자기가 이긴 사람들 List, second는 자기가 진 사람들 list
    queue<int> checks; // 확실히 순위를 알 수 있는 사람들
    int rank[n + 1];
    
    memset(rank, 0, sizeof(rank)); // rank 배열 초기화
    
    // 경기 결과 순회
    for(auto result: results) {
        int a = result[0];
        int b = result[1];
        
        players[a].first.insert(b);
        players[b].second.insert(a);
        
        if(players[a].first.size() + players[a].second.size() == n - 1) {
            checks.push(a);
        }
        if(players[b].first.size() + players[b].second.size() == n - 1) {
            checks.push(b);
        }
    }
    
    // 확실한 사람들의 순위 매기기
    while(!checks.empty()) {
        int now = checks.front();
        checks.pop();
        
        rank[now] = n - players[now].first.size();
        answer++;
        
        // 이긴 사람 리스트 업데이트 (N^3 = 1000000으로 시간복잡도 상 가능)
        for(auto lose: players[now].first) { 
            for(auto win: players[now].second) {
                // 이 노드한테 이긴 애들은 진 노드들한테도 이겼다고 분리
                players[win].first.insert(lose);
                
                // 이 노드한테 진 애들은 이긴 노드들한테도 졌다고 분리
                players[lose].second.insert(win);
                
                if(players[win].first.size() + players[win].second.size() == n - 1) {
                    checks.push(win);
                }
                if(players[lose].first.size() + players[lose].second.size() == n - 1) {
                    checks.push(lose);
                }
            }
        }
    }
    
    return answer;
}