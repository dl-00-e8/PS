#include <bits/stdc++.h>

using namespace std;

// 0: 트리 성립 불가, 1: 홀수 노드/짝수 노드, 2: 역홀수 노드 역짝수 노드
int check_node_type(int node, unordered_map<int, vector<int>>& graph, set<int>& visited) {
    visited.insert(node); // 방문 처리
    vector<int> child_list = graph[node];
    
    // 자식 노드 개수 확인
    int child_result = -1;
    int child_cnt = 0;
    for(auto child: child_list) {
        // 기존에 방문 처리된 노드일 경우, continue
        if(visited.find(child) != visited.end()) {
            continue;
        }

        // 자식 수 증가
        child_cnt++;
        int result = check_node_type(child, graph, visited);
        
        // 한 번도 갱신 안 되었을 때는, 갱신
        if(child_result == -1) {
            child_result = result;
        }
        else { // 갱신된 적이 있다면, 비교해서 다르면 0처리
            if(child_result != result) {
                return 0;
            }
        }
    }
    
    int result = 0;
    // 노드 번호 홀수
    if(node % 2 == 1) {
        if(child_cnt == 0 || child_cnt % 2 == 0) {
            result = 2;
        } else {
            result = 1;
        }
    // 노드 번호 짝수
    } else {
        if(child_cnt == 0 || child_cnt % 2 == 0) {
            result = 1;
        } else {
            result = 2;
        }
    }
    
    if(child_result != -1 && child_result != result) {
        result = 0;
    }
    
    // cout << node << " " << child_cnt << " " << result << "\n";
    
    
    return result;
} 

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    unordered_map<int, vector<int>> graph;
    
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
        int root = g.first; // 루트 Node 확정
       
        // cout << root << "\n";
        set<int> visited; // 방문한 적 있는 Node인지 체크하는 집합 선언
        int result = check_node_type(root, graph, visited);
        // cout << "result" << result << "\n";
       
        if(result == 1) {
            answer[0]++;
        } else if(result == 2) {
            answer[1]++;
        }   
    }
    
    return answer;
}