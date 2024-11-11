#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4); // 순서: 생성한 정점의 번호, 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수
    vector<int> graph[1000001]; 
    int dest_cnt[1000001]; // 노드가 목적지가 된 횟수 계산
    set<pair<int, int>> visited;
    
    // 방문 배열 초기화
    memset(dest_cnt, 0, sizeof(dest_cnt));
    
    int max_idx = 0;
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        dest_cnt[edge[1]]++;
        
        // 최대 index 확인 위한 업데이트
        max_idx = max(max_idx, edge[0]);
        max_idx = max(max_idx, edge[1]);
    }
    
    // 생성 노드 찾기
    for(int i = 1; i < max_idx + 1; i++) {
        if(dest_cnt[i] == false && graph[i].size() >= 2) {
            answer[0] = i;
            break;
        }
    }
    
    // 생성 노드 기준으로 그래프 모양 찾기
    for(auto node: graph[answer[0]]) {
        visited.insert({answer[0], node}); // 방문 처리 (앞으로 미사용)
        dest_cnt[node]--; // 목적지 횟수 감소
        int node_type = 1; // 1: 도넛 모양, 2: 막대 모양, 3: 8자 모양
        
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            // 막대 모양
            if(dest_cnt[now] <= 1 && graph[now].size() == 0) {
                node_type = 2;
                break;
            }
            
            // 도넛 모양
            if(dest_cnt[now] == 2 && graph[now].size() == 2) {
                node_type = 3;
                break;
            }
            
            for(auto next: graph[now]) {
                if(visited.find({now, next}) == visited.end()) {
                    visited.insert({now, next});
                    q.push(next);
                    break;
                }
            }
        }
        answer[node_type]++;
    }
    
    return answer;
}