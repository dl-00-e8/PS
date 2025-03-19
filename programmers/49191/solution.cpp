#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    pair<set<int>, set<int>> players[n + 1]; // Player의 경기 결과를 담고 있는 배열, first는 자기가 이긴 사람들 List, second는 자기가 진 사람들 list
    
    // 경기 결과 순회
    for(auto result: results) {
        int a = result[0];
        int b = result[1];
        
        players[a].first.insert(b);
        players[b].second.insert(a);
    }
    
    // BFS
    queue<int> q; // 진입 노드
    
    for(int i = 1; i < n + 1; i++) {
        q.push(i);
    }
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(auto lose: players[now].first) {
            bool lose_change = false;
            for(auto win: players[now].second) {
                bool win_change = false;
                // 이 노드한테 이긴 애들은 진 노드들한테도 이겼다고 분리
                if(players[win].first.find(lose) == players[win].first.end()) {
                    players[win].first.insert(lose);    
                    win_change = true;
                }
                
                // 이 노드한테 진 애들은 이긴 노드들한테도 졌다고 분리
                if(players[lose].second.find(win) == players[lose].second.end()) {
                    players[lose].second.insert(win);
                    lose_change = true;
                }
                
                if(win_change) {
                    q.push(win);
                }
            }
            if(lose_change) {
                q.push(lose);
            }
        }
    }
    
    // 결과 확인
    for(auto player: players) {
        if(player.first.size() + player.second.size() == n - 1) {
            answer++;
        }
    }
    
    return answer;
}