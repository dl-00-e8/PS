#include <bits/stdc++.h>

using namespace std;

// 자식 노드가 모두 동일한 타입인지 확인
int dfs(int node, bool root, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& node_type, unordered_map<int, int>& visited) {
    visited[node] = 1;
    int type = node_type[node];
    if(root) {
        // 루트는 진입간선이 없으므로 재계산
        if(node % 2 == graph[node].size() % 2) {
            type = 0;
        } else {
            type = 1;
        }
    }
    
    vector<int> child_list = graph[node];
    for(auto child: child_list) {
        if(visited[child]) {
            continue;
        }
        
        int child_type = dfs(child, 0, graph, node_type, visited);
        if(child_type != type) {
            return -1;
        }
    }
    
    return type;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> node_type; // 루트 트리가 아닐 때의 노드의 타입 정의
    
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
        vector<int> child = g.second;
        
        int child_cnt = child.size();
        if(child_cnt > 0) {
            child_cnt--;
        }
        
        if(node % 2 == child_cnt % 2) {
            node_type[node] = 0;
        } else {
            node_type[node] = 1;
        }
    }
    
    for(auto g: graph) {
        unordered_map<int, int> visited;
        int result = dfs(g.first, 1, graph, node_type, visited);
        if(result == -1) {
            continue;
        }
        answer[result]++;
    }
    
    return answer;
}