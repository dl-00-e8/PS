#include <bits/stdc++.h>

using namespace std;

// 자식 노드가 모두 동일한 타입인지 확인
void dfs(int node, int root, unordered_map<int, vector<int>>& graph, unordered_map<int, pair<int, int>>& set, unordered_map<int, int>& visited) {
    visited[node] = 1;
    if(node % 2 == graph[node].size() % 2) {
        set[root].first++;
    } else {
        set[root].second++;
    }
    
    vector<int> child_list = graph[node];
    for(auto child: child_list) {
        if(visited[child]) {
            continue;
        }
        
        dfs(child, root, graph, set, visited);
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> visited; // 방문 처리
    unordered_map<int, pair<int, int>> set; // 같은 트리에 속하는 걸 조회
    
    for(auto node: nodes) {
        // 요소가 존재하지 않을 경우
        if(graph.find(node) == graph.end()) {
            vector<int> tree;
            graph[node] = tree;
        }
    }
    
    // 간선 정보 업데이트
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    for(auto g: graph) {
        int node = g.first;
        
        if(visited[node]) {
            continue;
        }
        
        // 트리끼리 묶기
        dfs(g.first, g.first, graph, set, visited);
    }
    
    for(auto s: set) {
        if(s.second.first == 1) {
            answer[0]++;
        }
        if(s.second.second == 1) {
            answer[1]++;
        }
    }
    
    return answer;
}