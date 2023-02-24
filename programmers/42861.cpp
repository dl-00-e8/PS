#include <bits/stdc++.h>

using namespace std;

int parent[101];
int findParent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = findParent(parent, parent[x]);
    }
    
    return x;
}
void unionParent(int parent[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);
    
    if(pa < pb) {
        parent[pb] = pa;
    }
    else {
        parent[pa] = pb;
    }
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // parent 배열 이용
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    // 정렬 및 MST 진행
    for(int i = 0; i < costs.size(); i++) {
        pq.push({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        pq.pop();
        
        if(findParent(parent, x) != findParent(parent, y)) {
            unionParent(parent, x, y);
            answer += cost;
        }
    }
    
    return answer;
}